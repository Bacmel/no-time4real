CXX      :=  g++
CXXFLAGS := -Wall -std=c++11
LDFLAGS = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv) -lm -lWiringPi
SRC_DIR :=src
INC_DIR :=-I/include

INCLUDE = $(wildcard $(INC_DIR)/*.h)# Liste des fichiers Heather

SRC := $(wildcard $(SRC_DIR)/*.cpp) lidar.cpp  # Liste des fichiers sources pour le main
OBJ := $(SRC:.cpp=.o) # Liste des fichiers objets

all: lidar

main: $(OBJ)
	$(CXX) $(LDFLAGS) -o lidar $^ $(LIBS)

%.o: $(INCLUDE)


clean:
	rm -rf $(OBJ)
