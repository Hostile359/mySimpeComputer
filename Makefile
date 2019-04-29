OBJ = build/mySimpleComputer.o build/main.o build/myTerm.o build/myBigChars.o build/myReadkey.o
CC = gcc
CFLAGS  = -g3 -O0 -Wall -Werror -std=c99

.PHONY: clean open gdb

bin/prog: $(OBJ) bin res
	$(CC) $(CFLAGS) -o bin/prog $(OBJ) -lm

build/mySimpleComputer.o: src/mySimpleComputer.c build
	$(CC) $(CFLAGS) -o build/mySimpleComputer.o -c src/mySimpleComputer.c
	
build/myTerm.o: src/myTerm.c build
	$(CC) $(CFLAGS) -o build/myTerm.o -c src/myTerm.c
	
build/myBigChars.o: src/myBigChars.c build
	$(CC) $(CFLAGS) -o build/myBigChars.o -c src/myBigChars.c
	
build/myReadkey.o: src/myReadkey.c build
	$(CC) $(CFLAGS) -o build/myReadkey.o -c src/myReadkey.c

build/main.o: src/main.c build
	$(CC) $(CFLAGS) -o build/main.o -c src/main.c

build:
	mkdir -p build

bin:
	mkdir -p bin

res:
	mkdir -p resources
	touch resources/output.bin
	
clean :
	rm -rf build bin resources
open :
	./bin/prog
gdb :
	gdb ./bin/prog
