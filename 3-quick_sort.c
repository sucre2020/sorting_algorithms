#include "sort.h"

/**
 * partition - partition function for lomuto_sort
 * @ar: the array to be sorted
 * @lo: the lowest index
 * @hi: the highest index
 * @size: the size of the array
 * Return: nothing
 */
int partition(int *ar, int lo, int hi, size_t size)
{
	int pivot = ar[hi];
	int i, j, t;

	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (ar[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				t = ar[i];
				ar[i] = ar[j];
				ar[j] = t;
				print_array(ar, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		t = ar[i + 1];
		ar[i + 1] = ar[hi];
		ar[hi] = t;
		print_array(ar, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - sorts using the lomuto sort algorithm
 * @ar: the array to be sorted
 * @lo: the lowest index
 * @hi: the highest index
 * @size: the size of the array
 * Return: nothing
 */
void lomuto_sort(int *ar, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(ar, lo, hi, size);
		lomuto_sort(ar, lo, p - 1, size);
		lomuto_sort(ar, p + 1, hi, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using the Quick
 * sort algorithm.
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, 0, size - 1, size);
}
