

CXX      :=  g++
CXXFLAGS := -Wall -std=c++11
LDFLAGS  :=
LIBS :=
SRC_DIR :=src
INC_DIR :=-I/include

INCLUDE = $(wildcard $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.h)# Liste des fichiers Heather

SRC := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.cpp) lidar.c  # Liste des fichiers sources pour le main
OBJ := $(SRC:.cpp=.o) # Liste des fichiers objets

all: lidar

main: $(OBJ)
	$(CXX) $(LDFLAGS) -o lidar $^ $(LIBS)

%.o: $(INCLUDE)


clean:
	rm -rf $(OBJ)
