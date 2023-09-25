#include "sort.h"

void swaper(int *arr, int index_1, size_t index_2, int gab);

/**
 * shell_sort - sort an array of integer using the Shell Sort algrothim
 *              with knuth gab
 * @arr: the array of ineger to sort
 * @size: the size of the arr
 */

void shell_sort(int *arr, size_t size)
{
	size_t i = 0;
	int j = 0, gab = 0;

	if (arr == NULL || size < 2)
		return;
	while (gab <= (int)(size / 3))
		gab = gab * 3 + 1;
	while (gab > 0)
	{
		for (i = gab ; i < size ; i++)
			for (j = i - gab ; j >= 0 ; j -= gab)
			{
				if (arr[j] < arr[i])
					break;
				swaper(arr, j, i, gab);
			}
		gab /= 3;
		print_array(arr, size);
	}
}

/**
 * swaper - swap two number
 * @arr: the array of integer to swap at
 * @index_1: the first number
 * @index_2: the second number
 * @gab: the gab between them
 */

void swaper(int *arr, int index_1, size_t index_2, int gab)
{
	int temp = arr[index_1];

	arr[index_1] = arr[index_2];
	arr[index_2] = temp;

	while (index_1 - gab >= 0)
	{
		if (arr[index_1 - gab] > arr[index_1])
		{
			temp = arr[index_1 - gab];
			arr[index_1 - gab] = arr[index_1];
			arr[index_1] = temp;
		}
		index_1 -= gab;
	}
}
