obj-m:=module1.o  
KDIR := /lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(shell pwd) modules

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c