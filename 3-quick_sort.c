#include "sort.h"

/**
 * partitioning - partitioning the array according to aa randome
 *								selected number called pivot
 * @arr: the array to be partitioned
 * @lo: the start of the array
 * @hi: the end of the array
 * Return: the index of the pivot
 */

int partitioning(int *arr, int lo, int hi)
{
	int hd= lo, tl = lo - 1;
	int pivot = arr[hi], temp = 0;

	while (hd <= hi)
		{
			if (arr[hd] <= pivot)
	{

		/*swap the element in hd and t +1*/
		tl++;
		temp = arr[tl];
		arr[tl] = arr[hd];
		arr[hd] = temp;

	}
			hd++;
		}

	return (tl);
}


/**
 * quickSort - recursive quick sort algrothim
 * @arr: the arr to be sorted
 * @hi: the	last index on the arr
 * @lo: the first index on the arr
 * @size: the	size of the array
 */

void quickSort(int *arr, int lo, int hi, size_t size)
{
	int pivot;

	if (hi <= lo)
		return;
	
	pivot = partitioning(arr, lo, hi);
	print_array(arr, size);
	quickSort(arr, lo, pivot - 1, size);
	quickSort(arr, pivot + 1, hi, size);

}

/**
 * quick_sort - sort array of integer in ascending order using
 *							Quick sort algrothim
 * @arr: array of integer that will be sorted
 * @size: the size of the array
 */

void quick_sort(int *arr, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	quickSort(arr, lo, hi, size);
}
