#include "shell.h"

#define BUFFER_SIZE 128

static char *resize_buffer(char **lineptr, size_t *n, ssize_t line_len);

/**
 * read_line - reads a line of input from the user.
 *
 * Return: a pointer to the read line, or NULL on failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t getline_return;

	getline_return = _getline(&line, &len, fileno(stdin));

	if (getline_return == -1)
	{
		free(line);
		return (NULL);
	}

	/* Remove newline character from the input */
	if (line[getline_return - 1] == '\n')
	{
		line[getline_return - 1] = '\0';
	}

	return (line);
}

/**
* _getline - custom getline function.
* @lineptr: pointer to the buffer where the line is stored.
* @n: size of the buffer.
* @fd: file descriptor to read from.
*
* Return: the number of characters read, or -1 on failure.
*/
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_pos, buffer_size;
	size_t line_len = 0;
	char c = '\0';

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (c != '\n')
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				return ((line_len > 0) ? (ssize_t)line_len : -1);
			buffer_pos = 0;
		}
		c = buffer[buffer_pos++];
		if (line_len + 1 >= *n)
			*lineptr = resize_buffer(lineptr, n, line_len);
		(*lineptr)[line_len++] = c;
	}
	(*lineptr)[line_len] = '\0';
	return (line_len);
}

/**
* resize_buffer - doubles the buffer size.
* @lineptr: pointer to the buffer to be resized.
* @n: current size of the buffer.
* @line_len: current length of the line.
*
* Return: pointer to the resized buffer, or NULL on failure.
*/
static char *resize_buffer(char **lineptr, size_t *n, ssize_t line_len)
{
	char *new_line;

	*n *= 2;
	new_line = malloc(*n);
	if (new_line == NULL)
		return (NULL);
	_memcpy(new_line, *lineptr, line_len);
	free(*lineptr);
	return (new_line);
}
