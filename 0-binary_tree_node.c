#include "binary_trees.h"

/**
 * binary_tree_node -....
 * @parent: the father of the node
 * @value: the val to store
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
