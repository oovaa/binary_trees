#include "binary_trees.h"

/**
 * bst_insert - insert val in bst
 * @tree: double ptr to the root node of the bst to insert val
 * @value: val to store
 * Return: ptr  to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }
    return (bst_in_recur(*tree, value));
}

/**
 * bst_in_recur - recursively insert new node
 * @curr_n: ptr to the crrent node
 * @val: val to insert
 * @papa: ptr to parent
 * Return: ptr to the created node, or NULL on failure
 */
bst_t *bst_in_recur(bst_t *curr_n, int val)
{
    if (curr_n == NULL)
    {
        return (binary_tree_node(NULL, val));
    }

    if (val < curr_n->n)
    {
        if (curr_n->left == NULL)
        {
            curr_n->left = binary_tree_node(curr_n, val);
            return (curr_n->left);
        }

        else
        {
            return (bst_in_recur(curr_n->left, val));
        }
    }
    else if (val > curr_n->n)
    {
        if (curr_n->right == NULL)
        {
            curr_n->right = binary_tree_node(curr_n, val);
            return (curr_n->right);
        }
        else
        {
            return (bst_in_recur(curr_n->right, val));
        }
    }
    else
    {
        return (NULL);
    }
}