#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL avl_tree from an array.
 * @size: The no. of elements in @array.
 * @array: A pointer to the first element of the array to be converted.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t a, b;
	avl_t *avl_tree = NULL;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (avl_insert(&avl_tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (avl_tree);
}
