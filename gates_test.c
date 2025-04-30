/* Testing for the gates.c file */

#include <boolheader.h>
#define NUM_TESTS 2


int test_AND()
{

	int result = 0;
	
	int arr[2] = {1, 1};
	if (function_gate(AND_GATE, 2, arr) != 1)
	{
		result++;
	}

	arr[0] = 0;
	arr[1] = 0;
	if (function_gate(AND_GATE, 2, arr) != 0)
	{
		result++;
	}

	arr[1] = 1;
	if (function_gate(AND_GATE, 2, arr) != 0)
	{
		result++;
	}

	if (function_gate(AND_GATE, 0, arr) != -1)
	{
		result++;
	}

	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	if (function_gate(AND_GATE, 10, arr2) != 0)
	{
		result++;
	}

	return result;
}

int test_OR()
{

	int result = 0;
	
	int arr[2] = {1, 1};
	if (function_gate(OR_GATE, 2, arr) != 1)
	{
		result++;
	}

	arr[0] = 0;
	arr[1] = 0;
	if (function_gate(OR_GATE, 2, arr) != 0)
	{
		result++;
	}

	arr[1] = 1;
	if (function_gate(OR_GATE, 2, arr) != 1)
	{
		result++;
	}

	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	if (function_gate(OR_GATE, 10, arr2) != 1)
	{
		result++;
	}

	return result;
}

int test_NOT()
{
	int result = 0;
	int arr[1] = {1};

	if (function_gate(NOT_GATE, 1, arr) != 0)
	{
		result++;
	}

	arr[0] = 0;

	if (function_gate(NOT_GATE, 1, arr) != 1)
	{
		result++;
	}

	int arr1[2] = {1, 1};

	if (function_gate(NOT_GATE, 2, arr1) != -1)
	{
		result++;
	}

	return result;
}

int test_XOR()
{
	int result = 0;
	int arr[2] = {1, 0};

	if (function_gate(XOR_GATE, 2, arr) != 1)
	{
		result++;
	}

	arr[0] = 0;

	if (function_gate(XOR_GATE, 2, arr) != 0)
	{
		result++;
	}

	arr[0] = 1;
	arr[1] = 1;

	if (function_gate(XOR_GATE, 2, arr) != 0)
	{
		result++;
	}
	
	int	arr2[5] = {1, 1, 1, 0, 0};
	
	if (function_gate(XOR_GATE, 5, arr2) != 1)
	{
		result++;
	}

	return result;
}


typedef int (*TestDriver)();

TestDriver tests[] = {
	test_AND,
	test_OR,
	test_NOT,
	test_XOR
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
