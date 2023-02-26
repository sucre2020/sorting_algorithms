#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, t;
	int tmp;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				t = j;
			}
		}
		if (tmp != array[i])
		{
			array[i] = array[i] ^ array[t];
			array[t] = array[i] ^ array[t];
			array[i] = array[i] ^ array[t];
			print_array(array, size);
		}
	}
}
