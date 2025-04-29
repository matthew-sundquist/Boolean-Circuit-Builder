/* Created by Matthew Sundquist */
/* Contains Definitions for all Gate Types Currently Supported */

/* 

	Returns:
	0 -> off or low
	1 -> on or high
   -1 -> error

*/

#include <boolheader.h>

int function_gate(GateType type, int count, int *args)
{
	int result = 0;
	if (args == NULL)
		return -1;

	switch (type)
	{
		case AND_GATE:
			for (int i = 0; i < count; i++)
			{
				if (args[i] == 0)
					return 0;
			}

			return 1;
			break;

		case OR_GATE:
			for (int i = 0; i < count; i++)
			{
				if (args[i] == 1)
					return 1;
			}

			return 0;
			break;

		case XOR_GATE:
			for (int i = 0; i < count; i++)
			{
				result ^= args[i];
			}

			return result;
			break;

			
		case NOT_GATE:
			if (count != 1)
				return -1;

			if (args[0] >= 1)
				return 0;

			else if (args[0] == 0)
				return 1;

			break;

		default:
			break;
	}

	
	return -1;
	
	
}	
