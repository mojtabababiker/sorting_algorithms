#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    int array_1[] = {0, 7, 7, 7, 8, 10, 11};
    size_t n_1 = sizeof(array) / sizeof(array[0]);
    int array_2[] = {7, 19, 48, 0, 99, 13, 71, 13, 13, 52, 19, 96, 73, 86, 7};
    size_t n_2 = sizeof(array) / sizeof(array[0]);
    int *array_3 = NULL;
    size_t n_3 = 0;
    int array_4[] = {1};
    size_t n_4 = 1;


    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);

    printf("=========================================\n");
    print_array(array_1, n_1);
    printf("\n");
    bubble_sort(array_1, n_1);
    printf("\n");
    print_array(array_1, n_1);

    printf("=========================================\n");
    print_array(array_2, n_2);
    printf("\n");
    bubble_sort(array_2, n_2);
    printf("\n");
    print_array(array_2, n_2);

    printf("=========================================\n");
    print_array(array_3, n_3);
    printf("\n");
    bubble_sort(array_3, n_3);
    printf("\n");
    print_array(array_3, n_3);

    printf("=========================================\n");
    print_array(array_4, n_4);
    printf("\n");
    bubble_sort(array_4, n_4);
    printf("\n");
    print_array(array_4, n_4);


    return (0);
}
