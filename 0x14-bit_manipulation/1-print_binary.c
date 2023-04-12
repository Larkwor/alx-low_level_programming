#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i, j;

	/* Find the most significant bit */
	for (i = 0; i < (int)(sizeof(unsigned long int) * 8) - 1; i++)
	{
		if ((n >> (i + 1)) == 0)
			break;
	}

	/* Print binary digits from most to least significant */
	for (j = i; j >= 0; j--)
	{
		if ((n & (mask << j)) == 0)
			_putchar('0');
		else
			_putchar('1');
	}
}
