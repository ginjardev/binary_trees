#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @value: The value to be stored in the node to be inserted.
 * @tree: A double pointer to the root node of the BST to insert the value.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node, *new_left, *new_right;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			new_node = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			new_left = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (current->left = new_node);
		}
		else if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			new_right = binary_tree_node(current, value);
			if (new_node == NULL)
				return (NULL);
			return (current->right = new_node);
		}
	}
	return (NULL);
}
