OBJ = build/mySimpleComputer.o build/main.o
CC = gcc
CFLAGS  = -g3 -O0 -Wall -Werror -std=c99

.PHONY: clean open gdb

bin/prog: $(OBJ) bin
	$(CC) $(CFLAGS) -o bin/prog $(OBJ) -lm

build/mySimpleComputer.o: src/mySimpleComputer.c build
	$(CC) $(CFLAGS) -o build/mySimpleComputer.o -c src/mySimpleComputer.c

build/main.o: src/main.c build
	$(CC) $(CFLAGS) -o build/main.o -c src/main.c

build:
	mkdir build

bin:
	mkdir bin

clean :
	rm -rf build bin
open :
	./bin/prog
gdb :
	gdb ./bin/prog
