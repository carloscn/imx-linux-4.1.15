#!/bin/bash

# usage: ./copy /media/carlos/BOOT
cp -rf ./boot/zImage ${1}/zImage
cp -rf ./boot/dts/imx6ull-14x14-emmc-4.3-800x480-c.dtb ${1}/device.dtb
sync
eject ${1}
