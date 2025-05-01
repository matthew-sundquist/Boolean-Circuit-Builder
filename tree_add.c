/* Created by Matthew Sundquist */

#include <boolheader.h>

internalNode *createInternalNode(GateType type, int count, internalNode *parent)
{
	internalNode *newNode = (internalNode *) malloc(sizeof(internalNode));

	if (newNode == NULL)
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

	if (type == INTERNAL)
	{
		internalNode *int_node = (internalNode *) newNode;
		parent->nodes[0] = int_node;
		parent->leftType = INTERNAL;
	}

	else if (type == LEAF)
	{
		leafNode *leaf_node = (leafNode *) newNode;
		parent->left = leaf_node;
		parent->leftType = LEAF;
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
	{
		return -1;
	}

	if (type == INTERNAL)
	{
		internalNode *int_node = (internalNode *) newNode;
		parent->right = int_node;
		parent->rightType = INTERNAL;
	}

	else if (type == LEAF)
	{
		leafNode *leaf_node = (leafNode *) newNode;
		parent->right = leaf_node;
		parent->rightType = LEAF;
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

	
}



