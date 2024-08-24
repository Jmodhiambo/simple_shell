#include "shell.h"

/**
 * read_line - reads a line of input from the user
 *
 * Return: a pointer to the read line, or NULL on failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t getline_return;

	getline_return = my_getline(&line, &len, fileno(stdin));

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
