note:  The original `README` has been changed to `README.old`

# Compiling the Linux Kernel for IMX6

`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean`

`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- imx_v7_defconfig`

`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig` (optional)

`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- all -j16`

* The compiled output `zImage` is saved on `arch/arm/boot`
* The compiled `.dtb` files are saved on the `arch/arm/boot/dts`

# Starting compiled dirty Linux Kernel

## config nfs on your host

### installing nfs-kernel-server on your host
`sudo apt-get install nfs-kernel-server rpcbind`

### config exports on your host
`sudo vim /etc/exports`

and you need to add the NFS sharing path on the exports:
`/home/carlos/nfs *(rw,sync,no_root_squash)`

### changing the version of nfs-kernel-server

Note, the nfs version of ubuntu 20.04 is too high to transform file for uboot.
So we need to modify the version config manually by

`sudo vim /etc/default/nfs-kernel-server`

changing the version `RPCNFSDCOUNT="-V 2 8"`

### restarting the nfs

`sudo /etc/init.d/nfs-kernel-server restart`

## copy the zImage to the nfs

`cp -r arch/arm/boot/zImage /home/carlos/nfs`

`cp -r arch/arm/boot/dts/imx6ull-14x14-evk.dtb /home/carlos/nfs`

## some operations on your device uboot console

Ensure that the uboot args is `console=ttymxc0,115200 root=/dev/mmcblk1p2 rootwait rw`

`dhcp`

`nfs 80800000 192.168.31.2:/home/carlos/nfs/zImage`

`nfs 83000000 192.168.31.2:/home/carlos/nfs/imx6ull-14x14-evk.dtb`

`bootz 80800000 - 83000000`

## replacing new kernel zImage on EMMC

* Transfer the zImage from host to device by `scp -r arch/arm/boot/zImage root@192.168.31.210:/run/media/mmcblk1p1/zImage`
