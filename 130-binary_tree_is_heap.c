#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int lv = 1, rv = 1;

	/* if the tree ended then it is a heap */
	if (!tree)
		return (1);

	/* if the left kid is not ok, or its kids are not max heaps, return 0 */
	if (tree->left && tree->left->n > tree->n)
		lv = 0;
	else
		lv = binary_tree_is_heap(tree->left);

	/* if the right kid is not ok, or its kids are not max heaps, return 0 */
	if (tree->right && tree->right->n > tree->n)
		rv = 0;
	else
		rv = binary_tree_is_heap(tree->right);

	/* return 1 only if both left and right subtrees are max heaps */
	return (lv && rv);
}
