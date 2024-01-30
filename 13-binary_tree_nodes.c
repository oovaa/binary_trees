#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with min one child in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes with at least one child, or (0) if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num = 0;

	if (tree)
	{
		num += binary_tree_nodes(tree->left);
		num += binary_tree_nodes(tree->right);

		if (tree->left || tree->right)
			num += 1;
	}

	return (num);
}
