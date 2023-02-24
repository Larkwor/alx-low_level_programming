#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character C to stdout
 * @C: The character to print
 *
 * Return: On sucess 1.
 * on error, -1 is returned, and errno is set appropriately.
 */
int _putchar(charc)
{
	return(write(1, &c, 1));
}
