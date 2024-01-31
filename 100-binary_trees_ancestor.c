#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: ptr to first node
 * @second: ptr to second node
 * Return: ptr to lowest common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *
										 first,
									 const binary_tree_t *second)
{
	binary_tree_t *fa, *sa; /* first ancestor, second ancestor */

	if (first == NULL || second == NULL)
		return (NULL);

	fa = (binary_tree_t *)first;

	while (fa)
	{
		sa = (binary_tree_t *)second;
		while (sa)
		{
			if (fa == sa)
				return (fa);

			sa = sa->parent;
		}
		fa = fa->parent;
	}

	return (NULL);
}
