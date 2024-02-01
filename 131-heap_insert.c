#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1); /* Leaf nodes are considered full */

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0); /* If only one child is present, the tree is not full */
}

/**
 * Heapify - Performs heapify operation on a heap.
 * @root: Pointer to the root node of the heap.
 */
void Heapify(heap_t **root)
{
	heap_t *tmp, *new_root;

	if (!root || !*root)
		return;

	new_root = *root;

	while (new_root->parent && new_root->parent->n < new_root->n)
	{
		tmp = new_root->parent;

		if (tmp->left == new_root)
			tmp->left = new_root->left;
		else
			tmp->right = new_root->left;

		if (new_root->left)
			new_root->left->parent = tmp;

		new_root->left = tmp;

		if (tmp->right)
			tmp->right->parent = new_root;

		new_root->parent = tmp->parent;

		if (tmp->parent)
		{
			if (tmp->parent->left == tmp)
				tmp->parent->left = new_root;
			else
				tmp->parent->right = new_root;
		}
		else
		{
			*root = new_root;
		}

		tmp->parent = new_root;
	}
}

/**
 * insert_max_left - Inserts a node with the maximum value to the left.
 * @root: Pointer to the root node of the heap.
 * @node: Pointer to the node to be inserted.
 *
 * Return: Pointer to the newly inserted node.
 */
heap_t *insert_max_left(heap_t **root, heap_t *node)
{
	heap_t *cur;

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	cur = *root;

	while ((*root)->left)
		cur = cur->left;

	cur->left = node;
	node->parent = cur;

	Heapify(&node);

	return (node);
}

/**
 * heap_insert - Inserts a value into a max binary heap.
 * @root: Pointer to the root node of the heap.
 * @value: Value to be inserted into the heap.
 *
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *cur;

	if (!root || !*root)
		return (NULL);

	cur = *root;
	new_node = binary_tree_node(NULL, value);

	if (binary_tree_is_full(cur))
	{
		if (!cur->parent)
		{
			return (insert_max_left(root, new_node));
		}

		cur = cur->parent->right;
	}

	return (new_node);
}
