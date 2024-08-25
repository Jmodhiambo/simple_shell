#include "shell.h"

/**
* execute_command - executes command using execve.
* @input: pointer to the input.
*
* Return: void
*/

int execute_command(char *input[])
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execve(input[0], input, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		return (0);
	}
	return (-1);
}

/**
 * process_input - processes the input line and executes the command
 * @line: the input line
 *
 * Return: void
 */
void process_input(char *line)
{
	char *argv[30];
	int i = 0;
	char *token = _strtok(line, " "); /* Get the command */
	char *the_path;

	while (token != NULL)
	{
		argv[i] = token;
		token = _strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	env_variable(argv[0]);

	exiting(argv[0]);

	/* Find full path for the command if not an absolute path*/
	if (argv[0][0] != '/')
	{
		the_path = command_path(argv[0]);

		if (the_path == NULL)
		{
			my_printf("Command not found\n");
			return;
		}
		argv[0] = the_path; /* Parses the full path to argv */

	}

	if (execute_command(argv) == -1)
	{
		my_printf("Command not found\n");
	}
}

/**
* exiting - exits the shell if user inputs "exit".
* @command: if its exit command the shell exits.
*
* Return: void.
*/
void exiting(char *command)
{
	char *ext = "exit";

	if (strcmp(ext, command) == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
