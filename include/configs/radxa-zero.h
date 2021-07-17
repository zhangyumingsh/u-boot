/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration for the Radxa Zero
 *
 * Copyright (C) 2019 Baylibre, SAS
 * Author: Jerome Brunet <jbrunet@baylibre.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define BOOT_UUID "7E0DC62E-464E-48FE-B1E0-6457A12F3511;"
#define ROOT_UUID "6604DF74-56FE-490C-BC88-AF86667B84FF;"

#define PARTS_DEFAULT                                        \
	"uuid_disk=${uuid_gpt_disk};"  	\
	"name=boot,size=512M,bootable,uuid=" BOOT_UUID \
	"name=rootfs,size=-,uuid=" ROOT_UUID

#define PREBOOT_LOAD_LOGO \
		"if fatload ${mmcdev}:1 ${loadaddr} logo.bmp; then " \
			"bmp display ${loadaddr} m m;" \
		"fi;" \

#define CONFIG_EXTRA_ENV_SETTINGS \
	"stdin=" STDIN_CFG "\0" \
	"stdout=" STDOUT_CFG "\0" \
	"stderr=" STDOUT_CFG "\0" \
	"partitions=" PARTS_DEFAULT "\0" \
	"load_logo=" PREBOOT_LOAD_LOGO "\0" \
	"fdt_addr_r=0x08008000\0" \
	"scriptaddr=0x08000000\0" \
	"kernel_addr_r=0x08080000\0" \
	"pxefile_addr_r=0x01080000\0" \
	"ramdisk_addr_r=0x13000000\0" \
	"fdtfile=amlogic/" CONFIG_DEFAULT_DEVICE_TREE ".dtb\0" \
	BOOTENV

#include <configs/meson64.h>

#endif /* __CONFIG_H */
