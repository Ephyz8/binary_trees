#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *nw, *fp;
	int size, leaf, sb, bt, lvl, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (lvl = 0, sb = 1; leaf >= sb; sb *= 2, lvl++)
		leaf -= sb;
	/* subtract all nodes except for bottom-most lvl */

	for (bt = 1 << (lvl - 1); bt != 1; bt >>= 1)
		tree = leaf & bt ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leaf.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leaf on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	nw = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = nw) : (tree->left = nw);

	fp = nw;
	for (; fp->parent && (fp->n > fp->parent->n); fp = fp->parent)
	{
		temp = fp->n;
		fp->n = fp->parent->n;
		fp->parent->n = temp;
		nw = nw->parent;
	}
	/* Flip values with parent until parent value exceeds nw value */

	return (nw);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
