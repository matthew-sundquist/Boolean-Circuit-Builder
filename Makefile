# Created by Matthew Sundquist 

CC = gcc
CFLAGS = -pedantic -g -Wall
LDFLAGS = 
CPPFLAGS = -I.

.PHONY: clean test

clean: 
	rm -rf gates_test gates_test.o

test: gates_test

gates_test: gates_test.o boolheader.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) gates_test.o -o gates_test

gates_test.o: gates_test.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c gates_test.c -o gates_test.o
