obj-m +=module1.o
obj-m +=char.o
KDIR := /lib/modules/$(shell uname -r)/build

all : module utilisateur

utilisateur: utilisateur.o
	gcc -Wall -o utilisateur $^

module:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c

