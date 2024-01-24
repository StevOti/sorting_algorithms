#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: The array of integers to partition.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot = array[high];
    ssize_t i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap_ints(array + i, array + j);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        swap_ints(array + i + 1, array + high);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick sort.
 * @array: The array of integers to sort.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot_index = lomuto_partition(array, low, high, size);

        quicksort(array, low, pivot_index - 1, size);
        quicksort(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using Quick sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
