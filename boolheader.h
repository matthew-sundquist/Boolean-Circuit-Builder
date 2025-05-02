/* Created by Matthew Sundquist */


#ifndef GATES_H
#define GATES_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	INTERNAL,
	LEAF,
	NONE
} NodeType;

typedef enum {
	AND_GATE,
	OR_GATE,
	XOR_GATE,
	NOT_GATE,
} GateType;

int function_gate(GateType gate, int count, int *args);

typedef struct internalNode {
	void **nodes;
	NodeType *types;
	struct internalNode *parent;
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

internalNode *createInternalNode(GateType type, int count);
leafNode *createLeafNode(int data);
internalNode *createRoot(GateType type, int count);
int setLeft(NodeType type, void *newNode, internalNode *parent);
int setRight(NodeType type, void *newNode, internalNode *parent);
int setChild(NodeType type, void *newNode, internalNode *parent, int nodeNum);
#endif
