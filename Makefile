CC = g++
FLAGS = -Wall -g

BIN_DIR = ./bin/
INCLUDE_DIR = ./include/
OBJ_DIR = ./obj/
SRC_DIR = ./src/

MAIN = main
TARGET = tp03.out
SRC = $(wildcard $(SRC_DIR)*.cpp)
OBJ = $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

all: $(OBJ)
	$(CC) $(FLAGS) -o $(BIN_DIR)$(TARGET) $(OBJ)

# Delete build files
clean:
	rm -f ${BIN_DIR}/*.out
	rm -f ${OBJ_DIR}/*.o 