/* Created by Matthew Sundquist */

#include <boolheader.h>

internalNode *createInternalNode(GateType type, int count)
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

	newNode->nodes = malloc(sizeof(void *) * count);

	if (newNode->nodes == NULL)
	{
		free(newNode); //replace this!
		return NULL;
	}
	newNode->parent = NULL;
	newNode->count = count;
	newNode->gate = type;
	newNode->cur_num_children = 0;

	for(int i = 0; i < count; i++)
	{
		newNode->types[i] = NONE;
		newNode->nodes[i] = NULL;
	}

	return newNode;
}

leafNode *createLeafNode(int data)
{
	leafNode *newNode = (leafNode *) malloc(sizeof(leafNode));

	if (newNode == NULL)
		return NULL;
	
	newNode->parent = NULL;
	newNode->data = data;

	return newNode;
}

internalNode *createRoot(GateType type, int count)
{
	internalNode *newNode;

	if ((newNode = createInternalNode(type, count)) == NULL)
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
		parent->nodes[0] = newNode;
		parent->types[0] = INTERNAL;
	}

	else if (type == LEAF)
	{
		parent->nodes[0] = newNode;
		parent->types[0] = LEAF;
	}

	else
	{
		return -1;
	}
	
	internalNode *tmp = (internalNode *)(parent->nodes[0]);
	tmp->parent = parent;

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
		parent->nodes[1] = newNode;
		parent->types[1] = INTERNAL;
	}

	else if (type == LEAF)
	{
		parent->nodes[1] = newNode;
		parent->types[1] = LEAF;
	}

	else
	{
		return -1;
	}
	
	internalNode *tmp = (internalNode *)(parent->nodes[1]);
	tmp->parent = parent;

	return 0;
}

int setChild(NodeType type, void *newNode, internalNode *parent, int nodeNum)
{
	if (nodeNum < 0 || parent == NULL || newNode == NULL)
		return -1;
	
	if (nodeNum >= parent->count)
		return -1;
	
	parent->nodes[nodeNum] = newNode;

	if (type == INTERNAL)
	{
		parent->types[nodeNum] = INTERNAL;
	}

	else if (type == LEAF)
	{
		parent->types[nodeNum] = LEAF;
	}

	else
	{
		return -1;
	}

	internalNode *tmp = (internalNode *)(parent->nodes[nodeNum]);
	tmp->parent = parent;
	
	return 0;
}



