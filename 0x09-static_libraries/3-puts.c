#include "main.h"

/**
 * _puts- A function that prints a string
 * @str: The pointer variable
 *
 * Return: void
 * Student: Adewale
 */
void _puts(char *str)
{
	int strlen = 0;

	while (str[strlen] != '\0')
	{
		putchar(str[strlen]);
		strlen++;
	}
	putchar('\n');
}
