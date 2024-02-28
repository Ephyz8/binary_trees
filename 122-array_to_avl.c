#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x, y = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&root, array[x]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
