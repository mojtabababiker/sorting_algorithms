#include "sort.h"

/**
 * select - select the smallest number in the aray arr
 * @arr: the array of integer to search on
 * @i: the starting point
 * @size: the size of the array
 * Return: the index of the selceted number
 */
int selector(int *arr, size_t i, size_t size)
{
  size_t j = i;
  int sml_index = i;
  
  for (j = i ; j < size ; j++)
    {
      if (arr[j] < arr[sml_index])
	sml_index = j;
    }
  return (sml_index);
}

/**
 * selection_sort - sort an array of integer in ascending order
 *                  using Selection Sort algrothim
 * @arr: the array of integer to be sorted
 * @size: the size of the array
 */

void selection_sort(int *arr, size_t size)
{
  size_t i;
  int temp, sml_index;

  if (arr == NULL || size < 2)
    return;

  for (i = 0 ; i < size ; i++)
    {
      sml_index = selector(arr, i, size);
      temp = arr[sml_index];
      arr[sml_index] = arr[i];
      arr[i] = temp;
      print_array(arr, size);
    }
}
