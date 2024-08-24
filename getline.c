#include "shell.h"

/**
* my_getline - this is my getline function
* @lineptr: double pointer to the buffer storing string
* @n: the size of the buffer
* @fd: the file descriptor
*
* Return: returns users input
*/

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	static char buf[1024];
	static size_t buf_pos, buf_end;
	size_t line_len = 0;
	ssize_t bytes_read;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (buf_pos == buf_end)
		{
			bytes_read = read(fd, buf, sizeof(buf));
			if (bytes_read <= 0)
				return ((line_len > 0) ? (ssize_t)line_len : -1);
			buf_pos = 0;
			buf_end = bytes_read;
		}

		if (line_len + 1 >= *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[line_len++] = buf[buf_pos++];
		if ((*lineptr)[line_len - 1] == '\n')
			break;
	}

	(*lineptr)[line_len] = '\0';
	return (line_len);
}
