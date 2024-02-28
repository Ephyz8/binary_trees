#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	rotate = tree->right;
	tree->right = rotate->left;
	if (rotate->left != NULL)
	{
		rotate->left->parent = tree;
	}
	rotate->left = tree;
	rotate->parent = tree->parent;
	tree->parent = rotate;
	return (rotate);
}
