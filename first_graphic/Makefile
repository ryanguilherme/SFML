CC = g++
CFLAGS = -c
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: sfml-app

sfml-app: main.o
	$(CC) main.o -o sfml-app $(LFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o sfml-app

