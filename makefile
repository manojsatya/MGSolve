CC = g++
CFLAGS = -O3 -std=c++0x -Wall -Winline -Wshadow -ansi
DEPS = grid.h mgsolver.h
OBJ = main.o grid.o mgsolver.o
TARGET = mgsolve
RM = /bin/rm -f

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
$(TARGET): $(OBJ)
	g++ -o $@ $^ $(CFLAGS) 
clean:
	$(RM) $(TARGET)
	$(RM) solution.dat
	$(RM) *.o

