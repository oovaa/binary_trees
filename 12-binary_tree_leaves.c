#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
