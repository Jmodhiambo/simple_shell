#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

extern char **environ;


void my_printf(const char *message);
void _printf(const char *format, ...);
void my_prompt(void);
int execute_command(char *input[]);
char *read_line(void);
void process_input(char *line);
char *command_path(char *command);
void exiting(char *command, char *cmd2);
size_t env_variable(char *command, char *variable, char *value);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);
size_t _strlen(const char *str);
char *_strcpy(char *str1, const char *str2);
char *_strcat(char *str1, const char *str2);
char *_strchr(const char *str, int c);
void *_memcpy(void *dest, const void *src, size_t n);
size_t env_handle(char *cmd, char *cmd1, char *cmd2);

#endif /* SHELL_H */
