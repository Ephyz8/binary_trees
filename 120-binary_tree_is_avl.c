#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lt = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((lt > rt) ? lt : rt);
		}
}

/**
 * bal_avl - Auxiliar function to compare each subtree if its AVL.
 * @tree: node that point to the tree to check.
 * @high: node that point to the higher node selected
 * @lower: node that point to the lower node selected.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_lt, height_rt, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_lt = binary_tree_height(tree->left);
		height_rt = binary_tree_height(tree->right);
		balancer = height_lt > height_rt ? height_lt - height_rt : height_rt - height_lt;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: node that point to the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
