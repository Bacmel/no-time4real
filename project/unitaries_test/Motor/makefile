CC = g++
FLAGS =
LIBS = -lm -lWiringPi
obj-m += driver_interruption.o
KDIR := /lib/modules/$(shell uname -r)/build

all: module lidar

lidar: lidar.o
	$(CC) -wall -o lidar $(LIBS)

%.o: %.c %.cpp %.h
	$(CC) -o $@ -c $< $(FLAGS)

module:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c
