#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - A function that sorts an array using counting algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
    unsigned int i = 0;
    int *counter = NULL, *output = NULL, k = 0, j = 0;

    if (array == NULL || size < 2)
        return;

    // Find the maximum element in the array
    k = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }

    // Allocate memory for the counter array
    counter = malloc(sizeof(int) * (k + 1));
    if (counter == NULL)
        return;

    // Initialize counter array to 0
    for (j = 0; j <= k; j++)
        counter[j] = 0;

    // Count the occurrences of each element
    for (i = 0; i < size; i++)
        counter[array[i]] += 1;

    // Update counter array to contain actual positions in the output array
    for (j = 1; j <= k; j++)
        counter[j] += counter[j - 1];

    // Create the output array
    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(counter);
        return;
    }

    // Place elements in their correct positions in the output array
    for (i = size - 1; i < size; i--) // i is unsigned, so we check for i < size to avoid underflow.
    {
        j = array[i];
        output[counter[j] - 1] = array[i];
        counter[j] -= 1;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    // Free allocated memory
    free(counter);
    free(output);
}
