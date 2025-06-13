/* Created by Matthew Sundquist */
/* Tree Operations */

#include <boolheader.h>

/* recursivly traverses the tree and returns either a 1 or 0 */
int depth_first_recursive(void *node, NodeType type)
{

	if (type == INTERNAL)
	{
		/* internal node */
		/* recurse */
			
		internalNode *tmp = (internalNode *)(node);
		int values[tmp->count];

		for (int i = 0; i < tmp->count; i++)
		{
			results[i] = depth_first_recursive(tmp->nodes[i], tmp->types[i]);
		}
	}

	else
	{
		/* leaf node */
		/* do not recurse */

		leafNode *tmp = (leafNode *)(root->nodes[i]);

		return tmp->data;
	}

	
	internalNode *gate = (internalNode *)(node);

	return function_gate(internalNode->gate, gate->count, results);
}

int depth_first_tree(tree *tr)
{
	return depth_first_recursive(tr->root, INTERNAL);
}

int depth_first_node(internalNode *node)
{
	return depth_first_recursive(node, INTERNAL);
}
