KERN_DIR := /mnt/linux
ROOTFS_DIR := /mnt/minirootfs/rootfs

obj-m += mem.o

all:
	make -C $(KERN_DIR) M=$(PWD) modules

install:
	make -C $(KERN_DIR) M=$(PWD) INSTALL_MOD_PATH=$(ROOTFS_DIR) modules_install

clean:
	make -C $(KERN_DIR) M=$(PWD) clean
