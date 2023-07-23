#include "sort.h"

/**
 * bubble_sort - function that sort array by bubble sorting
 * @array : array to be sorted
 * @size : size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int flag = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
