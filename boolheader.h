/* Created by Matthew Sundquist */


#ifndef GATES_H
#define GATES_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	AND_GATE,
	OR_GATE,
	XOR_GATE,
	NOT_GATE,
} GateType;

int function_gate(GateType gate, int count, int *args);

typedef struct internalNode {
	struct internaNode *left, *right, *parent;
	int (*function_gate)(int count, int *args);
	GateType gate; 
} internalNode;

typedef struct leafNode {
	int data;
	struct internalNode *parent;
} leafNode;

#endif
