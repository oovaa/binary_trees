#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node , or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	root = binary_tree_node(NULL, array[0]);

	if (!root)
		return (NULL);

	for (i = 1; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
