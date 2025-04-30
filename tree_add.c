/* Created by Matthew Sundquist */

#include <boolheader.h>

internalNode *createInternalNode(GateType type, int count, internalNode *parent)
{
	internalNode *newNode = (internalNode *) malloc(sizeof(internalNode));

	if (newNode == NULL)
		return NULL;

	newNode->parent = (internalNode *) malloc(sizeof(internalNode));

	if (newNode->parent == NULL)
	{
		return NULL;
	}

	newNode->count = count;
	newNode->gate = type;
	newNode->parent = parent;

	return newNode;
}

leafNode *createLeafNode(int data, internalNode *parent)
{
	leafNode *newNode = (leafNode *) malloc(sizeof(leafNode));

	if (newNode == NULL)
		return NULL;

	newNode->parent = (internalNode *) malloc(sizeof(internalNode));

	if (newNode->parent == NULL)
	{
		return NULL;
	}

	newNode->data = data;
	newNode->parent = parent;

	return newNode;
}


