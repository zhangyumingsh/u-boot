#!/bin/bash

LOCALPATH=$(pwd)

export ARCH=arm64
export CROSS_COMPILE=${LOCALPATH}/../prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-

TOOLPATH=${LOCALPATH}/../rkbin/tools
PATH=$PATH:$TOOLPATH

finish() {
	echo -e "\e[31m MAKE UBOOT IMAGE FAILED.\e[0m"
	exit -1
}

trap finish ERR

#############################################################################################
make all
$TOOLPATH/loaderimage --pack --uboot ./u-boot-dtb.bin uboot.img 0x200000
#############################################################################################
echo "make idbloader.img"
tools/mkimage -n rk3399 -T rksd -d ../rkbin/bin/rk33/rk3399_ddr_800MHz_v1.14.bin idbloader.img
cat ../rkbin/bin/rk33/rk3399_miniloader_v1.15.bin >> idbloader.img
#############################################################################################
cp ../rkbin/bin/rk33/rk3399_loader_v1.12.112.bin .

#############################################################################################
cat >trust.ini <<EOF
[VERSION]
MAJOR=1
MINOR=0
[BL30_OPTION]
SEC=0
[BL31_OPTION]
SEC=1
PATH=../rkbin/bin/rk33/rk3399_bl31_v1.18.elf
ADDR=0x10000
[BL32_OPTION]
SEC=0
[BL33_OPTION]
SEC=0
[OUTPUT]
PATH=trust.img
EOF

$TOOLPATH/trust_merger trust.ini
rm -f trust.ini
##############################################################################################
echo -e "\e[36m U-boot IMAGE READY! \e[0m"
