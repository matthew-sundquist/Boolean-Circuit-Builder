/* Created by Matthew Sundquist */

#include <boolheader.h>

#define NUM_TESTS 2


int test_createInternalNode()
{
	int result = 0;
	internalNode *newNode = createInternalNode(AND_GATE, 2, NULL);
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
	leafNode *newNode = createLeafNode(1, NULL);
	
	if (newNode == NULL)
		result++;

	if (newNode->data != 1)
		result++;
	
	if (newNode->parent != NULL)
		result++;

	return result;
}



typedef int (*TestDriver)(); 

TestDriver tests[] = {
	test_createInternalNode,
	test_createLeafNode
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
