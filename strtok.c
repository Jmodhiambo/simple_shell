#include "shell.h"

/**
* _strtok - my custom strtok.
* @str: the string to be tokenized
* @delim: the delimeter
*
* Return: returns a pointer to a tokenized string
*/

char *_strtok(char *str, const char *delim)
{
	static char *saved_str;
	char *token;

	if (str != NULL)
	{
		saved_str = str;
	}

	if (saved_str == NULL)
		return (NULL);

	while (*saved_str && _strchr(delim, *saved_str))
	{
		saved_str++;
	}

	if (*saved_str == '\0')
		return (NULL);

	token = saved_str;

	while (*saved_str && !_strchr(delim, *saved_str))
	{
		saved_str++;
	}

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

/**
* _strchr - my custom strchr
* @str: a pointer to a string to find a character from
* @c: the character value of a character to find in the string
*
* Return: returns a pointer to the first position of the character
*/

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}

	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

/**
* _memcpy - my custom memcpy
* @dest: destination location for the copied data
* @src: the source of the data to be copied
* @n: number of character to copy
*
* Return: returns dest
*/

void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *dt = (char *)dest;
	const char *sc = (const char *)src;

	for (i = 0; i < n; i++)
	{
		dt[i] = sc[i];
	}

	return (dest);

}
