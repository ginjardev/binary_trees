#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @size: size of array
 * @array: input array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (help_sort(array, 0, size - 1, NULL));
}

/**
 * help_sort - helper func for sorted_array_to_avl
 * @array: input array
 * @end: final index
 * @start: beginning index
 * @parent: pointer to parent node
 * Return: newly created node
 */
avl_t *help_sort(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int centre;

	if (start > end)
		return (NULL);
	centre = (start + end) / 2;
	new_node = calloc(1, sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->n = array[centre];
	new_node->parent = parent;
	new_node->left = help_sort(array, start, centre - 1, new_node);
	new_node->right = help_sort(array, centre + 1, end, new_node);

	return (new_node);
}
