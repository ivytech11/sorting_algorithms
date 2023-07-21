#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 0;
	int aux;
{
	unsigned int i, j, gap;
	int aux;

	if (array == NULL || size < 2)
		return;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];

			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = aux;
		}

		print_array(array, size);
	}
}
