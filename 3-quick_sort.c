#include "sort.h"

/**
 * partitioning - partitioning the array according to a
 *	   	  randome selected number called pivot
 * @arr: the array to be partitioned
 * @lo: the start of the array
 * @hi: the end of the array
 * Return: the index of the pivot
 */

int partitioning(int *arr, int lo, int hi, size_t size)
{
	int head= lo, tail = lo - 1;
	int pivot = arr[hi], temp = 0;

	while (head <= hi)
	{
		if (arr[head] <= pivot)
		{
			tail++;
			temp = arr[tail];
			arr[tail] = arr[head];
			arr[head] = temp;
			if (arr[head] != arr[tail])
				print_array(arr, size);
		}
		head++;
	}
	return (tail);
}


/**
 * quickSort - recursive quick sort algrothim
 * @arr: the arr to be sorted
 * @lo: the first index on the arr
 * @hi: the last index on the arr
 * @size: the size of the array
 */

void quickSort(int *arr, int lo, int hi, size_t size)
{
	int pivot;

	if (hi <= lo)
		return;

	pivot = partitioning(arr, lo, hi, size);
	quickSort(arr, lo, pivot - 1, size);
	quickSort(arr, pivot + 1, hi, size);
}

/**
 * quick_sort - sort array of integer in ascending order
 * 		using Quick sort algrothim
 * @arr: array of integer that will be sorted
 * @size: the size of the array
 */

void quick_sort(int *arr, size_t size)
{
	int lo;
	int hi;

	if (arr == NULL || size < 2)
		return;
	lo = 0;
	hi = size - 1;
	quickSort(arr, lo, hi, size);
}
