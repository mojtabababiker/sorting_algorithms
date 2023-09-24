#include "sort.h"

/**
 * selection_sort - Sorts array of int
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two numbers
 * @val1 : First number
 * @val2 : Second number
 */
void swap(int *val1, int *val2)
{
	int temp = *val1;

	*val1 = *val2;
	*val2 = temp;
}
