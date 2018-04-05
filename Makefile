CC = g++
CFLAGS = -Wall -pedantic -Wextra -framework OpenGL -framework GLUT 
BIN = mmn11
OBJ = mmn11.o

mmn11: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

mmn11.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $@