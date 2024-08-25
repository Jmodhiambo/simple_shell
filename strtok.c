#include "shell.h"

/**
* _strtok - my custom strtok
* @str: the string to be tokenized
* @delim: the delimeter
*
* Return: returns a tokenized string
*/

char *_strtok(char *str, const char *delim)
{
	static char *saved_str;
	char *token;

	if (str != NULL)
		saved_str = str;

	if (saved_str == NULL)
		return (NULL);

	while (*saved_str && strchr(delim, *saved_str))
		saved_str++;

	if (*saved_str == '\0')
		return (NULL);

	token = saved_str;

	while (*saved_str && !strchr(delim, *saved_str))
		saved_str++;

	if (*saved_str != '\0')
	{
		*saved_str = '\0';
		saved_str++;
	}
	else
	{
		saved_str = NULL;
	}

	return (token);
}
