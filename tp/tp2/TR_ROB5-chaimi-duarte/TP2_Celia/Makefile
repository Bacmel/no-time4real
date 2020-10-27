CC= gcc
obj-m +=module1.o
obj-m +=char.o
KDIR := /lib/modules/$(shell uname -r)/build

all : module utilisateur

utilisateur: utilisateur.o
	$(CC) -Wall -o utilisateur $^

%.o: %.c %.h
	$(CC) -o $@ -c $< $(CFLAGS)

module:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c

