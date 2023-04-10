#include <stdio.h>
#include <stdlib.h>

/** 
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: A pointer to the name of the file.
 * @text_content: string
 * Return: actual number of letters it can read and print
 */
 
ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char *buffer = (char *)malloc(letters + 1);
    if (buffer == NULL) {
        fclose(file);
        return 0;
    }

    ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);
    if (bytes_read <= 0) {
        free(buffer);
        fclose(file);
        return 0;
    }

    ssize_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, stdout);
    free(buffer);
    fclose(file);

    if (bytes_written != bytes_read) {
        return 0;
    }

    return bytes_written;
}
