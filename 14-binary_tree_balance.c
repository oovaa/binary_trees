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

/**
 * binary_tree_node_height - calculate the height of the subtree rooted at the given node.
 * @node: pointer to the root node of the current subtree
 * @H: current height of subtree
 */

int binary_tree_node_height(const binary_tree_t *node, int H)
{
    if (node == NULL)
        return H;

    int leftH = binary_tree_node_height(node->left, H + 1);
    int rightH = binary_tree_node_height(node->right, H + 1);

    return (leftH > rightH ? leftH : rightH);
}
