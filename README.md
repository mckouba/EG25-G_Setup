


# EG25-G Setup

This is a doucmentation source for installing drivers for Quectel EG25-G wireless modem.  This has been tested on Linux kernel version 6.0.7, but should work on most others.

# Installation
Steps 1-3 may be able to be done with a kernel module.  Will test
### 1. Get source code for your current kernel
For senior design just use this command to get the newest kernel for the le potato boards
```sh
wget https://github.com/libre-computer-project/libretech-linux/archive/refs/heads/v6.0/libretech-master.zip
unzip libretech-master.zip
```
### 2. Modify kernel source
In the file [KERNEL]/drivers/usb/serial/usb_wwan.c add the code between the #if in the method usb_wwan_setup_urb
```C
static struct urb *usb_wwan_setup_urb(struct usb_serial *serial, int endpoint, int dir, void *ctx, char *buf, int len,void (*callback) (struct urb *)) {
        ……
        usb_fill_bulk_urb(urb, serial->dev,
        usb_sndbulkpipe(serial->dev, endpoint) | dir,
        buf, len, callback, ctx);
        #if 1 //Added by Quectel for zero packet
        if (dir == USB_DIR_OUT) {
            struct usb_device_descriptor *desc = &serial->dev->descriptor;
            if (desc->idVendor == cpu_to_le16(0x2C7C))
                urb->transfer_flags |= URB_ZERO_PACKET;
            }
        #endif
    return urb;
}
```

In the file [KERNEL]/drivers/usb/serial/option.c add the following code between the #if in the struct usb_serial_driver
```C
static struct usb_serial_driver option_1port_device = {
    ……
    #ifdef CONFIG_PM
    .suspend = usb_wwan_suspend,
    .resume = usb_wwan_resume,
    #if 1 //Added by Quectel
    .reset_resume = usb_wwan_resume,
    #endif
    #endif
};
```
and inside the method option_probe
```C
static int option_probe(struct usb_serial *serial, const struct usb_device_id *id) {
    struct usb_wwan_intf_private *data;
    ……
    #if 1 //Added by Quectel
    //Quectel modules’s interface 4 can be used as USB network device
        if (serial->dev->descriptor.idVendor == cpu_to_le16(0x2C7C)) {
        //some interfaces can be used as USB Network device (ecm, rndis, mbim)
        if (serial->interface->cur_altsetting->desc.bInterfaceClass != 0xFF) {
            return -ENODEV;
        }
        //interface 4 can be used as USB Network device (qmi)
            else if (serial->interface->cur_altsetting->desc.bInterfaceNumber >= 4) {
                return -ENODEV;
            }
        }
    #endif
    /* Store device id so we can use it during attach. */
    usb_set_serial_data(serial, (void *)id);
    return 0;
}
```
### 3. Select 
### . Get installer script and run it
```sh
wget https://github.com/mckouba/EG25-G_Setup/blob/main/scripts/install_driver.sh
sudo chmod +x install_driver.sh
sudo ./install_driver.sh
```

### . Reboot and make sure you select the right kernel



# Notes:

Original source for quecetel-CM: https://github.com/sixfab/Sixfab_QMI_Installer/raw/main/src/Quectel_QConnectManager_Linux_V1.6.1.zip

Original source for EC25 driver: https://www.quectel.com/ProductDownload/EC25.html


Changes Made from original:

EG25-Driver/05_Driver/Gobinet/GobiUSBNet.c:

Line 850-860:

Original:
```C
#if 1 //def DATA_MODE_RP
    /* make MAC addr easily distinguishable from an IP header */
    if ((pDev->net->dev_addr[0] & 0xd0) == 0x40) {
        /*clear this bit wil make usbnet apdater named as usbX(instead if ethX)*/
        pDev->net->dev_addr[0] |= 0x02;	/* set local assignment bit */
        pDev->net->dev_addr[0] &= 0xbf;	/* clear "IP" bit */
    }
#endif
```
Modified:
```C
#if 1 //def DATA_MODE_RP
    /* make MAC addr easily distinguishable from an IP header */
    if ((pDev->net->dev_addr[0] & 0xd0) == 0x40) {
        u8 addr = pDev->net->dev_addr[0];
        /*clear this bit wil make usbnet apdater named as usbX(instead if ethX)*/
        addr |= 0x02;	/* set local assignment bit */
        addr &= 0xbf;	/* clear "IP" bit */
        dev_addr_mod(pDev->net, 0, &addr, 1);
    }
#endif
```
EG25-Driver/05_Driver/QMI_WWAN/qmi_wwan_q.c


Original:
```C
if (possibly_iphdr(dev->net->dev_addr)) {
		dev->net->dev_addr[0] |= 0x02;	/* set local assignment bit */
		dev->net->dev_addr[0] &= 0xbf;	/* clear "IP" bit */
	}
```

Modified:
```C
	if (possibly_iphdr(dev->net->dev_addr)) {
		u8 addr = dev->net->dev_addr[0];

		addr |= 0x02;	/* set local assignment bit */
		addr &= 0xbf;	/* clear "IP" bit */
	
		dev_addr_mod(dev->net, 0, &addr, 1);
	}
```
This needed to be changed because in linux kernel version 5.16 changed netdev->dev_addr such that it cannot be written to directly anymore.
Due to this these files needed to be changed as they would not compile.