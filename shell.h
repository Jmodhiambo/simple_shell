#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>

extern char **environ;


void my_printf(const char *message);
void _printf(const char *format, ...);
void my_prompt(void);
int execute_command(char *input[]);
char *read_line(void);
void process_input(char *line);
char *command_path(char *command);
void exiting(char *command);
void env_variable(char *command);
ssize_t my_getline(char **lineptr, size_t *n, int fd);

#endif /* SHELL_H */
