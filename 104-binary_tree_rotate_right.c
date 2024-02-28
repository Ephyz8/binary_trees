#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	rotate = tree->left;
	tree->left = rotate->right;
	if (rotate->right != NULL)
	{
		rotate->right->parent = tree;
	}
	rotate->right = tree;
	rotate->parent = tree->parent;
	tree->parent = rotate;
	return (rotate);
}
