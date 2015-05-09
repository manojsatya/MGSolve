CC = g++
CFLAGS = -O3 -std=c++0x -Wall -Winline -Wshadow -ansi
DEPS = grid.h
OBJ = main.o grid.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
mgsolve: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) 
