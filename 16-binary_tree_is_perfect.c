#include "binary_trees.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 1;

	int left_height = binary_tree_node_height(tree->left, 0);
	int right_height = binary_tree_node_height(tree->right, 0);

	if (left_height == right_height && binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right))
		return 1;

	return 0;
}

/**
 * binary_tree_node_height - calculate height of subtree rooted at given node.
 * @node: pointer to the root node of the current subtree
 * @H: current height of subtree
 * Return: Height
 */

int binary_tree_node_height(const binary_tree_t *node, int H)
{
	if (node == NULL)
		return H;

	int left_height = binary_tree_node_height(node->left, H + 1);
	int right_height = binary_tree_node_height(node->right, H + 1);

	return (left_height > right_height ? left_height : right_height);
}