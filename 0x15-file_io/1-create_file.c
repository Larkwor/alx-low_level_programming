#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails
 */
int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    mode_t mode = S_IRUSR | S_IWUSR;
    int fd = open(filename, flags, mode);

    if (fd == -1) {
        return -1;
    }

    if (text_content != NULL) {
        size_t len = strlen(text_content);
        ssize_t ret = write(fd, text_content, len);

        if (ret == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}
