#include "main.h"
/**
 * print_number - prints an integer
 * @n: tracked var
 */
void print_number(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		putchar(45);
		x = -x;
	}
	if ((x / 10) > 0)
	{
		print_number(x / 10);
	}
	putchar((x % 10) + 48);
}
