## Determine if you are compiling on Docker or the Ubuntu host
ifneq ($(wildcard /.dockerenv),)
	KERN_DIR := /mnt/linux
	ROOTFS_DIR := /mnt/minirootfs/rootfs
else
	KERN_DIR := /usr/src/linux-headers-`uname -r`
	ROOTFS_DIR := /
endif


obj-m += mem.o
obj-m += kmem_cache.o
obj-m += buddy.o

all:
	make -C $(KERN_DIR) M=$(PWD) modules

install:
	make -C $(KERN_DIR) M=$(PWD) INSTALL_MOD_PATH=$(ROOTFS_DIR) modules_install

clean:
	make -C $(KERN_DIR) M=$(PWD) clean
