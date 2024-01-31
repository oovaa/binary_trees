#include "binary_trees.h"
#include <limits.h>
#include <stdbool.h>

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: Root node of the binary tree.
 * Return: 1 if the binary tree is BST, other 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
    int before = INT_MIN;
    return (tree == NULL) ? 0 : bst_inorder(tree, &before);
}

/**
 * bst_inorder - checks if a binary tree is a valid Binary Search Tree
 * @node: current node being checked
 * @before: ptr to the value visited before
 * Return: 1 if valid 0 if not
 */

int bst_inorder(const binary_tree_t *node, int *before)
{
    if (node == NULL)
        return (1);

    /* checking left tree*/
    /*checking current node*/
    /*update previous value to current node value*/
    /*check right tree*/

    return (bst_inorder(node->left, before) &&
            (node->n > *before ? (*before = node->n, true) : false) &&
            bst_inorder(node->right, before));
}