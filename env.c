#include "shell.h"

/**
* env_variable - prints enronment variables
* @command: the "env" commnad to print the variables
*
* Return: void.
*/

void env_variable(char *command)
{
	char *env_v = "env";
	char **env = environ;

	if (strcmp(env_v, command) == 0)
	{
		while (*env)
		{
			_printf("%s\n", *env);
			env++;

		}

	}

}
