#include "binary_trees.h"
#include <stdlib.h>
/**
 * heap_to_sorted_array - converts a BMH to a sorted arr of
 * integers
 * @size: address to store the size of the arr
 * @heap: pointer to the root node of the heap to convert
 * Return: sorted arr of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int collect, k = 0;
	size_t size_heap;

	if (!heap)
		return (NULL);
	size_heap = binary_tree_size(heap);
	*size = size_heap;
	arr = malloc(size_heap * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		collect = heap_extract(&heap);
		arr[k] = collect;
		k++;
	}
	return (arr);
}
