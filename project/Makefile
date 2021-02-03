CXX      :=  g++
CXXFLAGS := -Iinclude -Wall -std=c++11
LDFLAGS := $(shell pkg-config --cflags opencv)
LIBS := $(shell pkg-config --libs opencv) -lm -lwiringPi
obj-m += driver_interruption.o
KDIR := /lib/modules/$(shell uname -r)/build
SRC_DIR :=src
INC_DIR :=include

INCLUDE = $(wildcard $(INC_DIR)/*.h) # Liste des fichiers Heather

SRC := $(wildcard $(SRC_DIR)/*.cpp) main.cpp  # Liste des fichiers sources pour le main
OBJ := $(SRC:.cpp=.o) # Liste des fichiers objets

all: module main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)
	
%.o: %.c %.cpp %.h
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(LDFLAGS)

module:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -rf $(OBJ) *.[oas] .*.flags *.ko .*.cmd .*.d .*.tmp *.mod.c *.mod *.symvers *.order
