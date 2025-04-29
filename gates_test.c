/* Testing for the gates.c file */

#include <boolheader.h>

int main()
{
	
	internalNode newNode;
	internalNode *testNode = &newNode;
	testNode->gate = AND_GATE;
	
	int arr[2] = {1, 1};
	
	printf("%i", function_gate(AND_GATE, 2, arr));
		


	return 0;
}
