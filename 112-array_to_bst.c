#include "binary_trees.h"
/**
 * array_to_bst - builds a bst from array
 * @array: ptr to 1st element in array
 * @size: number of elements
 * Return: a ptr to root node of created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
    size_t i;
    bst_t *root = NULL;

    for (i = 0; i < size; i++)
    {
        if (bst_insert(&root, array[i]) == NULL)
        {
            free(root);
            return (NULL);
        }
    }
    return (root);
}