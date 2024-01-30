#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with min one child in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes with at least one child, or (0) if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes = binary_tree_nodes(tree->left);
	size_t right_nodes = binary_tree_nodes(tree->right);

	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
		return (1 + left_nodes + right_nodes);

	return (0);
}