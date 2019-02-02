BIN =../bin
LIB =../lib
SRC =../src
OBJ =../obj
MAKE =../make
INC =../inc

CC = g++
CFLAGS = -Wall -g -c -Wunused-variable
IFLAGS = -I$(INC)
LFLAGS = -L$(LIB)

all : $(BIN)/NQueens
  
$(BIN)/NQueens : $(OBJ)/nqueens.o $(OBJ)/cotton-runtime.o
	$(CC) $(OBJ)/cotton-runtime.o $(OBJ)/nqueens.o -o $(BIN)/NQueens -lpthread
	
$(OBJ)/cotton-runtime.o : $(SRC)/cotton-runtime.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)/cotton-runtime.cpp
	mv *.o $(OBJ)
	
$(OBJ)/nqueens.o : $(SRC)/nqueens.cpp 
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)/nqueens.cpp
	mv *.o $(OBJ)

clean : 
	rm -rf $(OBJ)/* $(LIB)/* $(BIN)/ ;mkdir $(BIN)
