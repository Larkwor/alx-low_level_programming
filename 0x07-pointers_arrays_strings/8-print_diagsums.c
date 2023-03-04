#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - print sum of diagonal matrix
 * @a: pointer to multidimensional array
 * @size: size of array
 */

void print_diagsums(int *a, int size)
{
	int i, j, k, rsum, lsum;

	rsum = lsum = 0;

	j = 0, k = size - 1;

	for (i = 0; i < size; ++i, j += size + 1, k += size - 1)
	{
		lsum += *(a + j);
		rsum += *(a + k);
	}
	printf("%d, %d\n", lsum, rsum);
}
