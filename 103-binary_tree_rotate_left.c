#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation on a BT
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	/* we are given the root we should replace it with it's right kid*/
	if (!tree || !tree->right)
		return (NULL);

	binary_tree_t *lc = tree->right, *the_parent = tree->parent;

	tree->right = lc->left;
	if (tree->right)
		tree->right->parent = tree;

	lc->left = tree;

	if (the_parent)
	{
		if (the_parent->left == tree)
			the_parent->left = lc;
		else
			the_parent->right = lc;
	}

	lc->parent = the_parent;
	tree->parent = lc;

	return (lc);
}
