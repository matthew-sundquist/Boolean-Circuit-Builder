# Created by Matthew Sundquist 

CC = gcc
CFLAGS = -pedantic -g -Wall
LDFLAGS =
CPPFLAGS = -I.

.PHONY: clean test

clean: 
	rm -rf gates_test gates_test.o libgates.a gates.o

libgates.a: gates.o boolheader.h
	ar rcs libgates.a gates.o

gates.o: gates.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c gates.c -o gates.o

test: gates_test 

gates_test: gates_test.o libgates.a
	$(CC) $(CPPFLAGS) $(LDFLAGS) -L. gates_test.o -lgates -o gates_test

gates_test.o: gates_test.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c gates_test.c -o gates_test.o
