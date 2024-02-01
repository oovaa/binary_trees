#include "binary_trees.h"

/**
 * array_to_heap - Converts an array to a Max Binary Heap.
 *
 * @array: Pointer to the array containing integer values.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node of the Max Binary Heap.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	/* Allocate space for the root pointer */
	heap_t **root = malloc(sizeof(heap_t *));

	/* Check if memory allocation was successful */
	if (!root)
		return (NULL);

	/* Initialize root pointer to NULL */
	*root = NULL;

	/* Insert each element from the array into the Max Heap */
	for (size_t i = 0; i < size; i++)
	{
		heap_insert(root, array[i]);
	}

	/* Return the root of the Max Heap */
	return (*root);
}
