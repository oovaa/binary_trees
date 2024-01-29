#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node, If node is NULL, return NULL,
 * If node has no uncle, return NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    if (node->parent->parent->left == NULL || node->parent->parent->right == NULL)
        return (NULL);

    if (node->parent == node->parent->parent->left)
        return (node->parent->parent->right);

    if (node->parent == node->parent->parent->right)
        return (node->parent->parent->left);

    return (NULL);
}