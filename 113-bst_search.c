#include "binary_trees.h"
/**
 * bst_search - search for val in bst
 * @tree: ptr to root of bst
 * @value: val to search
 * Return: a ptr to node containing a value equals to (value)
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else if (value < tree->n)
		return (bst_search(tree->left, value));

	return (NULL);
}
