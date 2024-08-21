#include "shell.h"

/**
* command_path - finds the path to commands without paths
* @command: the command from the user.
*
* Return: Returns the full path of the command.
*/

char *command_path(char *command)
{
	char *path = strdup(getenv("PATH")); /* Avoids modifying the original*/
	char *dir;
	char *fullpath;
	size_t len;

	if (path == NULL)
	{
		return (NULL);
	}

	dir = strtok(path, ":");

	while (dir != NULL)
	{
		/* The (+2) is for '/' and '\0' */
		len = strlen(dir) + strlen(command) + 2;

		fullpath = malloc(len);

		if (fullpath == NULL)
		{
			free(path);
			return (NULL);
		}

		strcpy(fullpath, dir);
		strcat(fullpath, "/");
		strcat(fullpath, command);

		/* Checks if the command is executable, if so returns the command */
		if (access(fullpath, X_OK) == 0)
		{
			free(path);
			return (fullpath);
		}
		free(fullpath); /* Frees fullpath if the command is not executable */
		dir = strtok(NULL, ":"); /* Moves to the next directory in the path*/
	}
	free(path);
	return (NULL);
}
