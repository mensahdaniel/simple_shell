#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

void isatty_handler(void);

char *get_path(char *path);
char *get_cmdpath(char *command);

long int _putchar(char c);
int printstr(char *str);

unsigned int long _strlen(char *str);
const char *_strchr(const char *str, char c);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int count);

char *_strtok(char *str, const char *delim);
char *_strdup(char *str);

int execute(char **args, char **argv);

#endif /* MAIN_H */
