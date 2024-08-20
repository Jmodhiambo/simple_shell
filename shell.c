#include "shell.h"

/**
* main - the starting point of the simple shell
*
* Return: always 0 when successful.
*/

int main(void)
{
	char *line = NULL;

	while (1)
	{
		my_prompt(); /*Displays my promt "#cisfun " */

		line = read_line(); /* Reads the input using getline */

		if (line == NULL)
			break;

		process_input(line); /* Process the input line */

		free(line);
	}

	return (0);
}

/**
* my_printf - prints to the screen
* @message: what to be printed
*
* Return: void
*/
void my_printf(const char *message)
{
	int i = 0;

	for (; message[i] != '\0'; i++)
	{
		write(STDOUT_FILENO, &message[i], 1);
	}
}

/**
* my_prompt - the prompt for my shell
*
* Return: void.
*/

void my_prompt(void)
{
	my_printf("#cisfun$ ");
}
