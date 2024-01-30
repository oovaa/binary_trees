#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int re = 0, leftH = 0, rightH = 0;

	if (tree == NULL)
		return (re);

	if (tree->left)
		leftH = binary_tree_node_height(tree->left, 0);

	if (tree->right)
		rightH = binary_tree_node_height(tree->right, 0);

	re = leftH - rightH;

	return (re);
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