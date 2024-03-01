#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary search tree from an array.
 * @size: The no. of elements in @array.
 * @array: A pointer to the first element of the array to be converted.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *bs_tree = NULL;
	size_t n, m;

	if (array == NULL)
		return (NULL);

	for (n = 0; n < size; n++)
	{
		for (m = 0; m < n; m++)
		{
			if (array[m] == array[n])
				break;
		}
		if (m == n)
		{
			if (bst_insert(&bs_tree, array[n]) == NULL)
				return (NULL);
		}
	}

	return (bs_tree);
}
