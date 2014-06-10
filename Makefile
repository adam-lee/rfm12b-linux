PWD := $(shell pwd)
obj-m += rfm12b.o

all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- M=$(PWD) -C $(KDIR) M=$(PWD) modules
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- M=$(PWD) -C $(KDIR) M=$(PWD) clean

