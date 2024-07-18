#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of
 * integers using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located. -1 If value
 * is not present in array or if array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step;
	size_t prev;
	size_t i;
	size_t start;
	size_t end;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	prev = 0;

	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
		if (prev >= size)
			break;
	}

	start = prev >= step ? prev - step : 0;
	end = prev >= size ? size : prev;
	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	for (i = start; i < end; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
