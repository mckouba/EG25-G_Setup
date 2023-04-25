#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xeb2058ac, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5efa3456, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x688bf5f, __VMLINUX_SYMBOL_STR(usbnet_tx_timeout) },
	{ 0xb3612d55, __VMLINUX_SYMBOL_STR(usbnet_change_mtu) },
	{ 0xcd026fae, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0x9e65b3d6, __VMLINUX_SYMBOL_STR(usbnet_start_xmit) },
	{ 0xcd4992e1, __VMLINUX_SYMBOL_STR(usbnet_stop) },
	{ 0x4415a2ad, __VMLINUX_SYMBOL_STR(usbnet_open) },
	{ 0x5b02c4b6, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xd20a4e9a, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xa5f1ff67, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xa0cb4045, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0x4b1f4a37, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0x75999af0, __VMLINUX_SYMBOL_STR(usbnet_probe) },
	{ 0x5ef51460, __VMLINUX_SYMBOL_STR(usbnet_skb_return) },
	{ 0x66c9754e, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0x6fe8f65a, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x5528a872, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xe0a8ecc0, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0x2f59782c, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0xf40f7ed4, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x17e1445, __VMLINUX_SYMBOL_STR(dev_queue_xmit) },
	{ 0x65756b46, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xc37e3828, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0xda9aa65e, __VMLINUX_SYMBOL_STR(usbnet_disconnect) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4e32d66a, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x7cf419b7, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0xe111ab49, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0xdc5e380a, __VMLINUX_SYMBOL_STR(usbnet_suspend) },
	{ 0xbb41e970, __VMLINUX_SYMBOL_STR(usbnet_resume) },
	{ 0x3b9328a6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x9a43386, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xe5ab0117, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0xeb1ff01, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0xd17e06bb, __VMLINUX_SYMBOL_STR(usb_cdc_wdm_register) },
	{ 0xcb5317bc, __VMLINUX_SYMBOL_STR(usbnet_get_endpoints) },
	{ 0xa10e1f40, __VMLINUX_SYMBOL_STR(usb_driver_claim_interface) },
	{ 0x3cd95e8a, __VMLINUX_SYMBOL_STR(usbnet_get_ethernet_addr) },
	{ 0x84542ac7, __VMLINUX_SYMBOL_STR(usb_ifnum_to_if) },
	{ 0x1204af8, __VMLINUX_SYMBOL_STR(eth_commit_mac_addr_change) },
	{ 0x1ab584b7, __VMLINUX_SYMBOL_STR(eth_prepare_mac_addr_change) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x98cf60b3, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x84bc974b, __VMLINUX_SYMBOL_STR(__arch_copy_from_user) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x82107dd2, __VMLINUX_SYMBOL_STR(usb_driver_release_interface) },
	{ 0xc45a2563, __VMLINUX_SYMBOL_STR(usb_autopm_put_interface) },
	{ 0x7c97c8a4, __VMLINUX_SYMBOL_STR(__ll_sc_atomic_add_return) },
	{ 0x917f1a3b, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x38d7c7e6, __VMLINUX_SYMBOL_STR(usb_autopm_get_interface) },
	{ 0xec2ac905, __VMLINUX_SYMBOL_STR(__ll_sc_atomic_sub_return) },
	{ 0xbce1a50b, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=cdc-wdm";

MODULE_ALIAS("usb:v05C6p9003d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v05C6p9215d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0125d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0121d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0191d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0195d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0306d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0512d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0296d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0435d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0620d*dc*dsc*dp*ic*isc*ip*in04*");
MODULE_ALIAS("usb:v2C7Cp0800d*dc*dsc*dp*ic*isc*ip*in04*");

MODULE_INFO(srcversion, "9EDD0DCE3652B74A0BF1776");
