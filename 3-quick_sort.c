#include "sort.h"

/**
 * swap_int - Swaps two integers
 * @a: first int
 * @b: second int
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of the array
 * Return: index of pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != high)
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_recursion - recursive quick sort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: array size
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_recursion(array, low, p - 1, size);
		quick_recursion(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts array using Quick sort (Lomuto)
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, 0, size - 1, size);
}
