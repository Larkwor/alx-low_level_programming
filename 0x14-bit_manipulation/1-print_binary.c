#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1, max_mask = ULONG_MAX;
	int shift = sizeof(unsigned long int) * 8 - 1;

	max_mask <<= shift;

	while (mask <= max_mask)
	{
		if ((n & max_mask) == 0)
			_putchar('0');
		else
			_putchar('1');

		mask <<= 1;
		shift--;

		if (shift < 0)
			break;
		max_mask >>= 1;
	}

	return;
}
