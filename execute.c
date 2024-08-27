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
	int status, i = 0;
	char *token = _strtok(line, " "); /* Get the command */
	char *the_path;

	while (token != NULL)
	{
		argv[i] = token;
		token = _strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	status = env_variable(argv[0], argv[1], argv[2]);
	if (status == 2)
		return; /* prevents further execution if env_varable is successful*/

	exiting(argv[0], argv[1]);

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
* @cmd2: optinal argument to check exit status.
*
* Return: void.
*/
void exiting(char *command, char *cmd2)
{
	char *ext = "exit";
	int ext_status;
	char *endptr;

	if (_strcmp(ext, command) != 0)
	{
		return;
	}

	if (cmd2 == NULL)
	{
		exit(0); /* exits because no arguments passed*/
	}

	if (cmd2 != NULL)
	{
		ext_status = strtol(cmd2, &endptr, 10); /* Converts the long int */

		if (*endptr != '\0' || ext_status < 0 || ext_status > 255)
		{
			my_printf("Invalid exit status\n");
			return;
		}

		exit(ext_status); /* Exit with a provided argument */
	}
}
