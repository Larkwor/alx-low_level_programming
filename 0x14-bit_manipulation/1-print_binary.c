#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
    unsigned long int mask = 1;
    int i, j;

    mask <<= (sizeof(unsigned long int) * 8) - 1;

    for (i = 0; i < (int)(sizeof(unsigned long int) * 8); i++)
    {
        j = n & mask ? 1 : 0;
        putchar(j + '0');
        mask >>= 1;
    }
}
