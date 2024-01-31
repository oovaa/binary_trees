#include "binary_trees.h"

/**
 * BT_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
int BT_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int lef = 0, rig = 0;

		lef = tree->left ? 1 + BT_height(tree->left) : 0;
		rig = tree->right ? 1 + BT_height(tree->right) : 0;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}

/**
 * is_BST - Checks if a binary tree is a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
int is_BST(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!is_BST(tree->left) || !is_BST(tree->right))
		return (0);

	return (1);
}

/**
 * all_heights_are_ok - Checks if the heights of subtrees are within bounds.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the heights are within bounds, 0 otherwise.
 */
int all_heights_are_ok(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	int left_height = BT_height(tree->left);
	int right_height = BT_height(tree->right);

	if (left_height > 1 || right_height > 1)
		return (0);

	return (all_heights_are_ok(tree->left) && all_heights_are_ok(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (is_BST(tree) && all_heights_are_ok(tree));
}
