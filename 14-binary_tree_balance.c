#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int leftH = binary_tree_height(tree->left);
    int rightH = binary_tree_height(tree->right);

    return (leftH - rightH);
}

#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t lef = 0, rig = 0;

        lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

        return ((lef > rig) ? lef : rig);
    }

    return (0);
}