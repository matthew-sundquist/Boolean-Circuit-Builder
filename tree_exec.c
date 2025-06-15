/* Created by Matthew Sundquist */
/* Tree Operations */

#include <boolheader.h>

/* recursivly traverses the tree and returns either a 1 or 0 */
int depth_first_recursive(void *node, NodeType type)
{

	if (node == NULL)
		return -1;
	
	if (type != INTERNAL && type != LEAF)
		return -1;
	
	
	if (type == INTERNAL)
	{
		/* internal node */
		/* recurse */
			
		internalNode *tmp = (internalNode *)(node);
		int results[tmp->count];
		
		for (int i = 0; i < tmp->count; i++)
		{
			results[i] = depth_first_recursive(tmp->nodes[i], tmp->types[i]);
		}

		return function_gate(tmp->gate, tmp->count, results); 
	}

	else
	{
		/* leaf node */
		/* do not recurse */
		
		leafNode *tmp = (leafNode *)(node);

		return tmp->data;
	}

	
}

int depth_first_tree(tree *tr)
{
	return depth_first_recursive(tr->root, INTERNAL);
}

int depth_first_node(internalNode *node)
{
	return depth_first_recursive(node, INTERNAL);
}
