#include "binary_trees.h"

/**
 * r_insert_node - node value instertion in a AVL.
 * @tree: type **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new: type**pointer left or right insertion.
 * @n_value: insertion value of the AVL.
 * Return: pointer to the new root after insertion otherwise NULL
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int n_value)
{
	int b_value;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, n_value));
	if ((*tree)->n > n_value)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, n_value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < n_value)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, n_value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	b_value = binary_tree_balance(*tree);
	if (b_value > 1 && (*tree)->left->n > n_value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_value > 1 && (*tree)->left->n < n_value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_value < -1 && (*tree)->right->n < n_value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (b_value < -1 && (*tree)->right->n > n_value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}
