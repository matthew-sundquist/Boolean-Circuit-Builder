/* Created by Matthew Sundquist */

#include <boolheader.h>

internalNode *createInternalNode(GateType type, int count, internalNode *parent)
{
	internalNode *newNode = (internalNode *) malloc(sizeof(internalNode));
	
	if (count < 1 || newNode == NULL)
		return NULL;
	
	newNode->types = (NodeType *) malloc(sizeof(NodeType) * count);

	if (newNode->types == NULL)
	{
		free(newNode);
		return NULL;
	}

	
	newNode->count = count;
	newNode->gate = type;
	newNode->parent = parent;
	newNode->nodes = NULL;

	for(int i = 0; i < count; i++)
	{
		newNode->types[i] = NONE;
	}

	return newNode;
}

leafNode *createLeafNode(int data, internalNode *parent)
{
	leafNode *newNode = (leafNode *) malloc(sizeof(leafNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = data;
	newNode->parent = parent;

	return newNode;
}

internalNode *createRoot(GateType type, int count)
{
	internalNode *newNode;

	if ((newNode = createInternalNode(type, count, NULL)) == NULL)
	{
		return NULL;
	}

	return newNode;
}


int setLeft(NodeType type, void *newNode, internalNode *parent)
{
	if (parent == NULL || newNode == NULL)
		return -1;

	if (parent->count != 2)
		return -1;

	if (type == INTERNAL)
	{
		internalNode *int_node = (internalNode *) newNode;
		parent->nodes[0] = int_node;
		parent->types[0] = INTERNAL;
	}

	else if (type == LEAF)
	{
		leafNode *leaf_node = (leafNode *) newNode;
		parent->nodes[0] = leaf_node;
		parent->types[0] = LEAF;
	}

	else
	{
		return -1;
	}

	return 0;
}

int setRight(NodeType type, void *newNode, internalNode *parent)
{
	if (parent == NULL || newNode == NULL)
		return -1;

	if (parent->count != 2)
		return -1;

	if (type == INTERNAL)
	{
		internalNode *int_node = (internalNode *) newNode;
		parent->nodes[1] = int_node;
		parent->types[1] = INTERNAL;
	}

	else if (type == LEAF)
	{
		leafNode *leaf_node = (leafNode *) newNode;
		parent->nodes[1] = leaf_node;
		parent->types[1] = LEAF;
	}

	else
	{
		return -1;
	}

	return 0;
}

int setChild(NodeType type, void *newNode, internalNode *parent, int nodeNum)
{
	if (nodeNum < 0 || parent == NULL || newNode == NULL)
		return -1;
	
	if (nodeNum >= parent->count)
		return -1;
	
	if (type == INTERNAL)
	{
		internalNode *int_node = (internalNode *) newNode;
		parent->nodes[nodeNum] = int_node;
		parent->types[nodeNum] = INTERNAL;
	}

	else if (type == LEAF)
	{
		leafNode *leaf_node = (leafNode *) newNode;
		parent->nodes[nodeNum] = leaf_node;
		parent->types[nodeNum] = LEAF;
	}

	else
	{
		return -1;
	}

	
	return 0;
}



