KERN_DIR := /mnt/linux

obj-m += test.o

all:
	make -C $(KERN_DIR) M=$(PWD) modules

clean:
	make -C $(KERN_DIR) M=$(PWD) clean
