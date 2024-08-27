#include "shell.h"

/**
* _strcmp - my custom strcmp.
* @str1: the first string
* @str2: the second string
*
* Return: 0 if the strings are equal and -1 if not
*/

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (-1);  /* Returns -1 if characters differ */
		}
		str1++;
		str2++;
	}

	/* Check if both strings ended at the same time */
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);  /* Returns 0 if string are the same */

	}
	else
	{
		return (-1);  /* One string longer hence not equal */
	}
}

/**
* _strdup - my custom strdup
* @str: a string to duplicate
*
* Return: returns a duplicated string.
*/
char *_strdup(const char *str)
{
	int len = 0;
	char *new_str;
	int i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1; /* Extra byte for '\0'*/

	new_str = malloc(len); /* Allocates memory for the duplicate */

	if (new_str == NULL)
	{
		free(new_str);
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		new_str[i] = str[i];
	}
	new_str[i] = '\0';

	return (new_str); /* Returns a pointer to the new string. */
}

/**
* _strlen - my custom strlen
* @str: the string to find its length
*
* Return: the length of the string.
*/
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

/**
* _strcat - my custom strcpy
* @str1: the first to have the second appended to
* @str2: the second string to append to the first one.
*
* Return: returns str1 appended to str2
*/

char *_strcat(char *str1, const char *str2)
{
	char *start = str1;  /* Keep the original pointer of str1 */

	while (*str1 != '\0')
	{
		str1++;
	}

	/* Append str2 to str1 */
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}

	*str1 = '\0';  /* Add null terminator at the end */

	return (start);  /* Return the original pointer of str1 */
}

/**
 * _strcpy - my custom strcpy
 * @str1: destination string
 * @str2: source string
 *
 * Return: pointer to the destination string.
 */
char *_strcpy(char *str1, const char *str2)
{
	char *str1_ptr = str1;

	while (*str2 != '\0')
	{
		*str1 = *str2;  /* Copy each character from src to dest */
		str1++;
		str2++;
	}
	*str1 = '\0';

	return (str1_ptr);
}
