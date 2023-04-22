#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: Number to be converted to binary and printed
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
if (n == 0)
{
putchar('0');
return;
}

if (n == 1)
{
putchar('1');
return;
}

print_binary(n >> 1);
putchar((n & 1) + '0');
}
