#include "main.h"

/**
 * _isalpha - Check for alphabetc character.
 * @c: character to check.
 *
 * Return: 1 if c is an alphabetic character
 * 0 if otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
	|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
