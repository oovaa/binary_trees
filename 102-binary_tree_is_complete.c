#include "binary_trees.h"
/**
 * binary_tree_is_complete - is binary tree complete ?
 * @tree: ptr to root node of tree
 * Return: 0 if tree is null
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL) /*empty = 0*/
		return (0);

	binary_tree_t **q = malloc(sizeof(binary_tree_t *) * 1000);

	if (q == NULL) /*mem alloc failed = 0*/
		return (0);

	int in = -1;  /*index for going in*/
	int out = -1; /*index for going out */

	q[in + 1] = (binary_tree_t *)tree; /*root goes in*/

	for (; in > out; out = out + 1) /*level traversal*/
	{
		binary_tree_t *now = q[out]; /*node goes out*/

		if (now == NULL) /*if current node is NULL, check if complete*/
		{
			while (in > out) /*check next nodes till we find a non-NULL one*/
			{
				now = q[out]; /*out to process*/
				if (now)	  /*if non-null node is found after null, return 0*/
				{
					free(q);
					return (0);
				}
				out = out + 1; /*go to next element*/
			}
		}
		else /*L&R children for non-null node goes in*/
		{
			q[in + 1] = now->left;	/*left goes in*/
			q[in + 1] = now->right; /*right goes in*/
		}
	}
	free(q);
	return (1); /*if all is there, tree is complete*/
}
