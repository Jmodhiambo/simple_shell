#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void my_printf(const char *message);
void my_prompt(void);
int execute_command(char *input[]);
char *read_line(void);
void process_input(char *line);
char *command_path(char *command);
void exiting(char *command);

#endif /* SHELL_H */
