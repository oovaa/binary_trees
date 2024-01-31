#include "binary_trees.h"

#include "binary_trees.h"

/**
 * temp_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

size_t temp_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (tree == NULL)
		return (0);

	for (; tree->parent != NULL; tree = tree->parent)
	{
		dep++;
	}

	return (dep);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: ptr to first node
 * @second: ptr to second node
 * Return: ptr to lowest common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	return (NULL);
}
