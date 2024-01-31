#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a BT
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *lc, *the_parent;
	/* we are given the root we should replace it with it's left kid*/
	if (!tree || !tree->left)
		return (NULL);

	lc = tree->left;
	the_parent = tree->parent;

	tree->left = lc->right;
	if (tree->left)
		tree->left->parent = tree;

	lc->right = tree;

	if (the_parent)
	{
		if (the_parent->right == tree)
			the_parent->right = lc;
		else
			the_parent->left = lc;
	}

	lc->parent = the_parent;
	tree->parent = lc;

	return (lc);
}
