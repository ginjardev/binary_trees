#include "limits.h"
#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rgt = 0;

		lft = tree->left ? 1 + height(tree->left) : 1;
		rgt = tree->right ? 1 + height(tree->right) : 1;
		return ((lft > rgt) ? lft : rgt);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @hi: The value of the largest node visited this far.
 * @lo: The value of the smallest node visited thus far.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t l_hgt, r_hgt, variance;
	int var1, var2;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		r_hgt = height(tree->right);
		l_hgt = height(tree->left);
		variance = l_hgt > r_hgt ? l_hgt - r_hgt : r_hgt - l_hgt;
		if (variance > 1)
			return (0);

		var1 = is_avl_helper(tree->left, lo, tree->n - 1);
		var2 = is_avl_helper(tree->right, tree->n + 1, hi);

		return (var1 && var2);
	}
	return (1);
}

/**
 * binary_tree_is_avl - Sees if a BT is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
