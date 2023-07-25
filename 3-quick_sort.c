#include "sort.h"

void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
void swap_ints(int *c, int *x);
int lomuto_partition(int *array, size_t size, int low, int high);

/**
 * swap_ints - swaps two integers
 * @c: first integer to swap
 * @x: second integer to swap
 */
void swap_ints(int *c, int *x)
{
	int tmp;

	tmp = *c;
	*c = *x;
	*x = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers
 * @array: array of integers
 * @size: size of the array
 * @low: starting index of the subset to order
 * @high: ending index of the subset to order
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, up, down;

	pivot = array + high;
	for (up = down = low; down < high; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @low: starting index of the array partition to order
 * @high: ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 * Description: Uses the Lomuto partition scheme to sort
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
