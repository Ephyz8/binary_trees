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
			lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lt > rt) ? lt : rt);
	}
}
/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(level_t **head, const binary_tree_t *tree, size_t level)
{
	level_t *new, *aux;

	new = malloc(sizeof(level_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}

/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(level_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @funct: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*funct)(int))
{
	level_t *head, *aux;
	size_t height = 0, cnt = 0;

	if (!tree || !funct)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (cnt <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (cnt == aux->n)
				{
					funct(aux->node->n);
				}
				aux = aux->next;
			}
			cnt++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
