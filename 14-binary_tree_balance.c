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

    int leftH = binary_tree_node_height(tree->left, 0);
    int rightH = binary_tree_node_height(tree->right, 0);

    return (leftH - rightH);
}

int binary_tree_node_height(const binary_tree_t *node, int height)
{
    if (node == NULL)
        return height;

    int left_height = binary_tree_node_height(node->left, height + 1);
    int right_height = binary_tree_node_height(node->right, height + 1);

    return (left_height > right_height ? left_height : right_height);
}