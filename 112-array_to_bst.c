#include "binary_trees.h"
/**
 * array_to_bst - builds a bst from array
 * @array: ptr to 1st element in array
 * @size: number of elements
 * Return: a ptr to root node of created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;

    for (size_t i = 0; array && i < size; bst_insert(&root, array[i]))
        ;

    return (root);
}