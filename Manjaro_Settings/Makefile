SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.out, $(SRC))
 
all: $(OBJ)
$(OBJ): $(SRC)
	g++ -g $(SRC) -o $(OBJ) -Wall -std=c++14 -O2 -Weffc++

clean:
	rm -rf $(OBJ)