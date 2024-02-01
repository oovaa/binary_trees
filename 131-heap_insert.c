#include "binary_trees.h"
heap_t *insert_recursive(heap_t *root, int value);
heap_t *swap_up(heap_t *node);
void swap_values(int *a, int *b);

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to insert into the heap.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	return (insert_recursive(*root, value));
}

/**
 * insert_recursive - Recursively inserts a value into the Max Binary Heap.
 *
 * @root: A pointer to the root node of the Heap.
 * @value: The value to insert.
 *
 * Return: A pointer to the created node.
 */
heap_t *insert_recursive(heap_t *root, int value)
{
	if (!root->left)
	{
		root->left = binary_tree_node(root, value);
		return (swap_up(root->left));
	}
	else if (!root->right)
	{
		root->right = binary_tree_node(root, value);
		return (swap_up(root->right));
	}
	else if (binary_tree_size(root->left) <= binary_tree_size(root->right))
	{
		return (insert_recursive(root->left, value));
	}
	else
	{
		return (insert_recursive(root->right, value));
	}
}

/**
 * swap_up - Swaps the node up the Max Binary Heap.
 *
 * @node: A pointer to the node to swap.
 *
 * Return: A pointer to the swapped node.
 */
heap_t *swap_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(&(node->n), &(node->parent->n));
		node = node->parent;
	}

	return (node);
}

/**
 * swap_values - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: A pointer to the tree to be measured.
 *
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
