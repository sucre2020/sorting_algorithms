#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, k;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			k = j + 1;
			if (k < size)
			{
				if (array[j] > array[k])
				{
					array[j] = array[j] ^ array[k];
					array[k] = array[j] ^ array[k];
					array[j] = array[j] ^ array[k];
					print_array(array, size);
				}
			}
		}
	}

}
