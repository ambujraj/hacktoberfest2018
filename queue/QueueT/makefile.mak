CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: main

main: main.o
	$(CC) main.o -o ds.exe

main.o: src/main.cpp include/Queue.hpp
	$(CC) -c src/main.cpp

clean:
	del *.o
