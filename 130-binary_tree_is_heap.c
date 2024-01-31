#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	int left_check, right_check;

	if (tree->left && !(tree->left->n < tree->n))
		return (0);

	left_check = binary_tree_is_heap(tree->left);

	if (tree->right && !(tree->right->n < tree->n))
		return (0);

	right_check = binary_tree_is_heap(tree->right);

	return (left_check && right_check);
}
