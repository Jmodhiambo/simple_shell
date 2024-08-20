#include "shell.h"

/**
* execute_command - executes command using execve.
* @input: pointer to the input.
*
* Return: void
*/

int execute_command(char *input)
{
	pid_t child = fork();
	char *argv[2];

	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		argv[0] = input; /* Assigns input to argv[0] */
		argv[1] = NULL; /* Terminates the array with NULL */

		execve(input, argv, NULL);
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
	char *token = strtok(line, " "); /* Get the command */

	if (token != NULL)
	{
		if (execute_command(token) == -1)
		{
			my_printf("Command not found\n");
		}
	}
}
