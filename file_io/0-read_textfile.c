#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters it should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r_bytes, w_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	r_bytes = read(fd, buffer, letters);
	if (r_bytes == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	w_bytes = write(STDOUT_FILENO, buffer, r_bytes);
	if (w_bytes == -1 || w_bytes != r_bytes)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (w_bytes);
}
