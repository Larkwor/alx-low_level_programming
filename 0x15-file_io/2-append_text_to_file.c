#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file to append the text to.
 * @text_content: A pointer to a string to append to the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or there are no permissions to write - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;

		w = write(o, text_content, len);
		if (w == -1)
		{
			close(o);
			return (-1);
		}
	}

	close(o);

	return (1);
}
