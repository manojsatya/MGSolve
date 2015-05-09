CC = g++
CFLAGS = -O3 -std=c++0x -Wall -Winline -Wshadow -ansi
DEPS = grid.h
OBJ = main.o grid.o
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

