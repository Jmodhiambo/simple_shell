#include "shell.h"

/**
* env_variable - prints enronment variables.
* @command: the "env" commnad to print the variables
* @variable: the environment variable for setenv and unsetenv
* @value: the set value for the variable
*
* Return: void.
*/

size_t env_variable(char *command, char *variable, char *value)
{
	char *env_v = "env";
	char **env = environ;
	char *unset = "unsetenv";

	if (_strcmp(env_v, command) == 0)
	{
		while (*env)
		{
			_printf("%s\n", *env);
			env++;

		}

	}

	else if (_strcmp(command, "setenv") == 0 || _strcmp(command, unset) == 0)
	{
		env_handle(command, variable, value);
		return (2); /* let process_input prevent further execution of seccess*/
	}

	return (0);
}

/**
* env_handle - sets or unsets evironment variable
* @cmd: unsetenv or setenv commnad
* @cmd1: the environment variable to set or unset
* @cmd2: the value to set to a variable incase of setenv
*
* Return: void
*/

size_t env_handle(char *cmd, char *cmd1, char *cmd2)
{
	char *set = "setenv";
	char *unset = "unsetenv";

	if (_strcmp(set, cmd) == 0)
	{
		if (cmd1 == NULL || cmd2 == NULL)
		{
			perror("Missing arguments");
			return (1);
		}
		if (setenv(cmd1, cmd2, 1) == -1)
		{
			perror("setenv");
			return (1);
		}
	}

	else if (_strcmp(unset, cmd) == 0)
	{
		if (cmd1 == NULL)
		{
			perror("Missing argument");
			return (1);
		}
		if (unsetenv(cmd1) == -1)
		{
			perror("unsetenv");
			return (1);
		}
	}

	else
	{
		return (1);
	}

	return (0);
}
