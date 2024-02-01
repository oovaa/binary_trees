#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created Max Binary Heap, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	heap_t *root = binary_tree_node(NULL, array[0]);

	if (!root)
		return (NULL);

	for (size_t i = 1; i < size; i++)
	{
		heap_t *new_node = binary_tree_node(NULL, array[i]);

		if (!new_node)
			return (NULL);

		heap_insert(&root, array[i]);
	}

	return (root);
}