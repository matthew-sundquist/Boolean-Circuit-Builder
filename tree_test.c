/* Created by Matthew Sundquist */

#include <boolheader.h>

#define NUM_TESTS 5


int test_createInternalNode()
{
	int result = 0;
	internalNode *newNode = createInternalNode(AND_GATE, 2);
	if (newNode == NULL)
		result++;

	if (newNode->count != 2)
		result++;
	
	if (newNode->parent != NULL)
		result++;

	if (newNode->gate != AND_GATE)
		result++;

	return result;
}

int test_createLeafNode()
{
	int result = 0;
	leafNode *newNode = createLeafNode(1);
	
	if (newNode == NULL)
		result++;

	if (newNode->data != 1)
		result++;
	
	if (newNode->parent != NULL)
		result++;

	return result;
}

int test_createRoot()
{
	int result = 0;
	
	internalNode *newRoot = createRoot(AND_GATE, 3);

	if (newRoot == NULL)
		result++;
	
	if (newRoot->count != 3)
		result++;
	
	if (newRoot->gate != AND_GATE)
		result++;

	internalNode *nullNode = createRoot(NONE, 0);

	if (nullNode != NULL)
		printf("FAILED");

	return result;
}


/* Since setLeft is the same as setRight I will not test setRight */
int test_setLeft()
{
	int result = 0;

	internalNode *parent = createRoot(AND_GATE, 2);
	internalNode *child = createInternalNode(OR_GATE, 2);
	if (child == NULL || parent == NULL)
		printf("Malloc Failed to Create New Node");
	
	setLeft(INTERNAL, child, parent);

	internalNode *firstChild = (internalNode *)parent->nodes[0];
		
	if (firstChild->gate != OR_GATE)
		result++;
	
	if (setLeft(INTERNAL, child, NULL) != -1)
		result++;
	
	internalNode *newParent = createRoot(AND_GATE, 1);

	if (setLeft(INTERNAL, child, newParent) != -1)
		result++;

	internalNode *newParent2 = createRoot(AND_GATE, 2);
	leafNode *child2 = createLeafNode(1);

	if (setLeft(LEAF, child2, newParent2) != 0)
		result++;
	
	if (newParent2->nodes[0] != child2)
		result++;
	
	internalNode *tmp = parent->nodes[0];

	if (tmp->parent != parent)
		result++;

	return result;
}

int test_setChild()
{
	int	result = 0;

	internalNode *root = createRoot(AND_GATE, 4);

	leafNode *child0 = createLeafNode(1);
	leafNode *child1 = createLeafNode(0);
	internalNode *child2 = createInternalNode(OR_GATE, 2);
	internalNode *child3 = createInternalNode(NOT_GATE, 1);

	if (setChild(LEAF, child0, root, 0) != 0)
		result++;
	if (setChild(LEAF, child1, root, 1) != 0)
		result++;
	if (setChild(INTERNAL, child2, root, 2) != 0)
		result++;
	if (setChild(INTERNAL, child3, root, 3) != 0)
		result++;

	if (root->nodes[0] != child0)
		result++;
	
	if (root->nodes[1] != child1)
		result++;
	
	if (root->nodes[2] != child2)
		result++;
	
	if (root->nodes[3] != child3)
		result++;
	

	for (int i = 0; i < 4; i++)
	{
		internalNode *tmp = (internalNode *)(root->nodes[i]);

		if (tmp->parent != root)
			result++;
	}
 
	return result;
}

typedef int (*TestDriver)(); 

TestDriver tests[] = {
	test_createInternalNode,
	test_createLeafNode,
	test_createRoot,
	test_setLeft,
	test_setChild
};

int main()
{
	int failed = 0;                                                                                
	for (int i = 0; i < NUM_TESTS; i++)                                         
	{                                                                           
		int result = tests[i]();                                                
		if (result != 0)                                                       
		{                                                                       
			printf("Test %d failed with code %d\n", i + 1, result);             
			failed++;                                                           
		}                                                                       
	}

	return failed;
}
