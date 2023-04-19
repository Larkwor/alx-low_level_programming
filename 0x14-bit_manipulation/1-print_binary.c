#include <stdio.h>

/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be converted to binary and printed
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
    else if (n == 1)
    {
        putchar('1');
        return;
    }
    else
    {
        print_binary(n >> 1);
        putchar((n & 1) + '0');
    }
}

int main(void)
{
    unsigned long int num = 10; // Example number
    printf("The binary representation of %lu is: ", num);
    print_binary(num);
    printf("\n");
    return 0;
}
