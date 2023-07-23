#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_fun(array, 0, size - 1, size);
}

/**
 * quick_sort_fun - sorts an array of integers in ascending order
 * @low : low index
 * @high : high index
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void quick_sort_fun(int array[], int low, int high, size_t size)
{
	int pos;

	if (low < high)
	{
		pos = partition(array, low, high, size);
		quick_sort_fun(array, low, pos - 1, size);
		quick_sort_fun(array, pos + 1, high, size);
	}
}

/**
 * partition - get position of pivot
 * @low : low index
 * @high : high index
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: position of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int i = low;
	int pivot = array[high];
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
				swap_q(&array[j], &array[i], size, array);
			i++;
		}
	}
	swap_q(&array[i], &array[high], size, array);
	return (i);
}

/**
 * swap_q - to swap between two element
 * @a : 1st element
 * @b : 2nd element
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void swap_q(int *a, int *b, size_t size, int *array)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}
