#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{

	int re = 0, leftH = 0, rightH = 0;

	if (tree == NULL)
	{
		re = 0;
		return (re);
	}
	leftH = binary_tree_node_height(tree->left, 0);
	rightH = binary_tree_node_height(tree->right, 0);

	if (leftH != rightH)
	{
		re = 0;
		return (re);
	}

	if (leftH == rightH)
		re = 1;
	else
		re = 0;

	return (re);
}

/**
 * binary_tree_node_height - calculate height of subtree rooted at given node.
 * @node: pointer to the root node of the current subtree
 * @H: current height of subtree
 * Return: Height
 */

int binary_tree_node_height(const binary_tree_t *node, int H)
{
	int re = 0, leftH = 0, rightH = 0;

	if (node == NULL)
	{
		re = H;
		return (re);
	}

	leftH = binary_tree_node_height(node->left, H + 1);
	rightH = binary_tree_node_height(node->right, H + 1);
	re = leftH > rightH ? leftH : rightH;

	return (re);
}
