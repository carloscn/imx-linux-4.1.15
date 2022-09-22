BASEINCLUDE	?= /lib/modules/`uname -r`/build
#BASEINCLUDE	?= /home/carlos/workspace/work/linux-imx-rel_imx_4.1.15_2.1.0_ga
mysum-objs	:= sum.o
myhello-objs	:=	hello.o

obj-m	+=  mysum.o
obj-m	+=	myhello.o



all	:
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;
clean	:
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) clean;
	rm -rf *.ko