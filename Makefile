# Created by Matthew Sundquist 

CC = gcc
CFLAGS = -pedantic -g -Wall
LDFLAGS =
CPPFLAGS = -I.

.PHONY: clean test

clean: 
	rm -rf gates_test gates_test.o libgates.a gates.o tree_test.o tree_add.o libtree.a tree_test

libgates.a: gates.o boolheader.h
	ar rcs libgates.a gates.o 

libtree.a: tree_add.o tree_exec.o boolheader.h
	ar rcs libtree.a tree_add.o tree_exec.o

gates.o: gates.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c gates.c -o gates.o

tree_add.o: tree_add.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c tree_add.c -o tree_add.o

tree_exec.o: tree_exec.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c tree_exec.c -o tree_exec.o

test: gates_test tree_test

gates_test: gates_test.o libgates.a
	$(CC) $(CPPFLAGS) $(LDFLAGS) -L. gates_test.o -lgates -o gates_test

gates_test.o: gates_test.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c gates_test.c -o gates_test.o

tree_test: tree_test.o libtree.a libgates.a
	$(CC) $(CPPFLAGS) $(LDFLAGS) -L. tree_test.o -ltree -lgates -o tree_test

tree_test.o: tree_test.c boolheader.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c tree_test.c -o tree_test.o
