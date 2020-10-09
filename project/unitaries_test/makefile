FLAGS = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv) -lm -lWiringPi

all: i2c.c
	gcc $(FLAGS) @< -o test $(LIBS)
