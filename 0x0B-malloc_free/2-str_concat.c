#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars.
 * @size: size of the array.
 * @c: storaged char
 * Return: pointer of an array of chars
 * betty style doc for function main goes there
 */
char *create_array(unsigned int size, char c)
{
char *al;
unsigned int i;
if (size == 0)
return (NULL);
al = malloc(sizeof(c) * size);
if (al == NULL)
return (NULL);
for (i = 0; i < size; i++)
al[i] = c;
return (al);
}
