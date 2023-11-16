#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 50

extern char **environ;
// extern char *args[SIZE];

void isatty_handler(void);

char *get_path(char *path);
char *get_cmdpath(char *command);

long int _putchar(char c);
int printstr(char *str);

size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *_strchr(const char *str, char c);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int count);

char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
char *_strdup(char *str);

int _printerror(char *cmd, char *argv, int count);

char *_itoa(int num);
void _free(char **args);

int builtincmd(char *cmds);
char **tokenizer(char *lineptr, char *delim);
int execute(char **cmds, char **argv, int count);

#endif /* MAIN_H */
