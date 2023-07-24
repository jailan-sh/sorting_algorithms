#include "sort.h"

/**
 * partition_hoare - get position of pivot
 * @low : low index
 * @high : high index
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: position of the pivot
 */

int partition_hoare(int *array, int low, int high, size_t size)
{
	int i = low, tmp;
	int pivot = array[high];
	int j = high;

	for (i = low, j = high; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (i);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);

	}
}

/**
 * quick_hoare - sorts an array of integers in ascending order
 * @low : low index
 * @high : high index
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void quick_hoare(int array[], int low, int high, size_t size)
{
	int pos;

	if (low < high)
	{
		pos = partition_hoare(array, low, high, size);
		quick_hoare(array, low, pos - 1, size);
		quick_hoare(array, pos, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_hoare(array, 0, size - 1, size);
}
