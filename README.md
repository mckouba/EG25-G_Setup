#

Original source for quecetel-CM: https://github.com/sixfab/Sixfab_QMI_Installer/raw/main/src/Quectel_QConnectManager_Linux_V1.6.1.zip

Original source for EC25 driver: https://www.quectel.com/ProductDownload/EC25.html







Changes Made from original:

EG25-Driver/05_Driver/Gobinet/GobiUSBNet.c:

Line 850-860:

Original:
#if 1 //def DATA_MODE_RP
    /* make MAC addr easily distinguishable from an IP header */
    if ((pDev->net->dev_addr[0] & 0xd0) == 0x40) {
        /*clear this bit wil make usbnet apdater named as usbX(instead if ethX)*/
        pDev->net->dev_addr[0] |= 0x02;	/* set local assignment bit */
        pDev->net->dev_addr[0] &= 0xbf;	/* clear "IP" bit */
    }
#endif

Modified:

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

EG25-Driver/05_Driver/QMI_WWAN/qmi_wwan_q.c


Original:

if (possibly_iphdr(dev->net->dev_addr)) {
		dev->net->dev_addr[0] |= 0x02;	/* set local assignment bit */
		dev->net->dev_addr[0] &= 0xbf;	/* clear "IP" bit */
	}


Modified:

	if (possibly_iphdr(dev->net->dev_addr)) {
		u8 addr = dev->net->dev_addr[0];

		addr |= 0x02;	/* set local assignment bit */
		addr &= 0xbf;	/* clear "IP" bit */
	
		dev_addr_mod(dev->net, 0, &addr, 1);
	}

This needed to be changed because in linux kernel version 5.16 changed netdev->dev_addr such that it cannot be written to directly anymore.
Due to this these files needed to be changed as they would not compile.