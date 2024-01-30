#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_node_height(tree->left, 0);
	right_height = binary_tree_node_height(tree->right, 0);

	if (left_height == right_height)
		return (1);

	return (0);
}

/**
 * binary_tree_node_height - calculate height of subtree rooted at given node.
 * @node: pointer to the root node of the current subtree
 * @H: current height of subtree
 * Return: Height of the subtree
 */

int binary_tree_node_height(const binary_tree_t *node, int H)
{
	int left_height, right_height;

	if (node == NULL)
		return (H);

	left_height = binary_tree_node_height(node->left, H + 1);
	right_height = binary_tree_node_height(node->right, H + 1);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * is_leaf - check if leaf
 * @node: pointer to node to check
 * Return: 1 leaf 0 other
 */
int is_leaf(const binary_tree_t *node)
{
	return (node && node->left == NULL && node->right == NULL);
}
