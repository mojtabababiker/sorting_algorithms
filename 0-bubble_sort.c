#include "sort.h"
#include <stdbool.h>

/**
 * swaps - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swaps(int *a, int *b)
{
	int temps;

	temps = *a;
	*a = *b;
	*b = temps;
}

/**
 * bubble_sort - sort array of integer using the Bubble Sort algrothim
 * @array: the array of integer to be sorted
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	bool swaped = false;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swaps(array + i, array + i + 1);
				print_array(array, size);
				swaped = false;
			}
		}
		if (!swaped)
			break;
	}
}
