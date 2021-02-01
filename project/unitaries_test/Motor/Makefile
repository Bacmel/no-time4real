CXX = g++
CXXFLAGS = -g -Wall
LIBS = -lm -lwiringPi
obj-m += driver_interruption.o
KDIR := /lib/modules/$(shell uname -r)/build

all: module lidar

lidar: lidar.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LIBS)

%.o: %.c %.cpp %.h
	$(CXX) -o $@ -c $< $(LDFLAGS)

module:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -f *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c
