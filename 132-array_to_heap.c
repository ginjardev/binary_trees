#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @size: size of array
 * @array: input array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t k = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	for (k = 0; k < size; k++)
	{
		heap_insert(&root, array[k]);
	}
	return (root);
}
