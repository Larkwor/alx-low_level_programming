#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int bit = 1;
	unsigned long int max_mask = 1 << (sizeof(unsigned long int) * 8 - 1);

	while (max_mask > 0)
	{
		if ((n & bit) == 0)
			_putchar('0');
		else
			_putchar('1');

		bit <<= 1;
		max_mask >>= 1;
	}

	return;
}
