#include "main.h"
#include <string.h>
/**
 * _strncpy - copies a string
 * @dest: string to be copied into
 * @src: string to be copied
 * @n: number of strings to be copied (bytes)
 * Return:  dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	strncpy(dest, src, n);

	return (dest);
}
