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
	int LH;
	int RH;

	if (tree == NULL)
		return 1;

	LH = b_height(tree->left);
	RH = b_height(tree->right);

	if (LH == RH && binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right))
		return 1;

	return 0;
}

/**
 * b_height - calculate height of subtree rooted at given node.
 * @node: pointer to the root node of the current subtree
 * @H: current height of subtree
 * Return: Height
 */

int b_height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	int LH = b_height(node->left);
	int RH = b_height(node->right);

	return (1 + MAX(LH, RH));
}