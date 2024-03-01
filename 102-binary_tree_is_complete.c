#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->left == NULL && node->right == NULL);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *lft, *rgt;
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	lft = tree->left;
	rgt = tree->right;
	r_height = binary_tree_height(rgt);
	l_height = binary_tree_height(lft);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(lft) && binary_tree_is_complete(rgt))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(lft) && binary_tree_is_perfect(rgt))
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *lft, *rgt;

	if (tree == NULL)
		return (1);
	rgt = tree->right;
	lft = tree->left;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (lft == NULL || rgt == NULL)
		return (0);
	if (binary_tree_height(lft) == binary_tree_height(rgt))
	{
		if (binary_tree_is_perfect(lft) && binary_tree_is_perfect(rgt))
			return (1);
	}
	return (0);
}
