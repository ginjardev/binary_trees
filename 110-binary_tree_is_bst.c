#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @hi: The value of the largest node visited this far.
 * @lo: The value of the smallest node visited thus far.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	int right_valid;
	int left_valid;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		right_valid = is_bst_helper(tree->right, tree->n + 1, hi);
		left_valid = is_bst_helper(tree->left, lo, tree->n - 1);

		return (left_valid && right_valid);
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
