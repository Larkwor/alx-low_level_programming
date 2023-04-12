#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to print in binary
 */
void print_binary(unsigned long int n)
{
    int i, size = sizeof(unsigned long int) * 8;
    unsigned long int mask = 1UL << (size - 1);

    for (i = 0; i < size; i++)
    {
        if ((n & mask) == 0)
            _putchar('0');
        else
            _putchar('1');

        mask >>= 1;
    }
}
