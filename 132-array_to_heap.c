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
	heap_t **root = malloc(sizeof(heap_t *));

	for (size_t i = 0; i < size; i++)
	{
		heap_insert(root, array[i]);
	}
	return (*root);
}
