/* Testing for the gates.c file */

#include <boolheader.h>
#define NUM_TESTS 1


int test_AND()
{

	int result = 0;
	
	int arr[2] = {1, 1};
	if (function_gate(AND_GATE, 2, arr) != 1)
	{
		result++;
	}

	return result;
}


typedef int (*TestDriver)();

TestDriver tests[] = {
	test_AND
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
