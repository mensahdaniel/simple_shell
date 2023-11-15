#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 256

extern char **environ;
extern char *args;

void isatty_handler(void);

char *get_path(char *path);
char *get_cmdpath(char *command);

long int _putchar(char c);
int printstr(char *str);

unsigned int long _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strchr(const char *str, char c);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int count);

char *_strtok(char *str, const char *delim);
char *_strdup(char *str);

int builtincmd(char **cmds);
char **tokenizer(char *lineptr, char *delim);
int execute(char **cmds, char **argv);

#endif /* MAIN_H */
