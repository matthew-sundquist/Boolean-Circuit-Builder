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
	struct internalNode *left, *right, *parent;
	int count;
	GateType gate; 
} internalNode;

typedef struct leafNode {
	int data;
	struct internalNode *parent;
} leafNode;

typedef struct tree {
	struct internalNode *root;
} tree;

internalNode *createInternalNode(GateType type, int count, internalNode *parent);
leafNode *createLeafNode(int data, internalNode *parent);

#endif
