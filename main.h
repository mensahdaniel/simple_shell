#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 50
#define BUFFSIZE 1024
#define PATH_MAX 1024
#define PROMPT "(HSH)>>$ "

extern char **environ;

void isatty_handler(void);
void signal_handler(int sig);

char *get_path(char *path);
char *get_cmdpath(char *command);

long int _putchar(char c);
int printstr(char *str);

size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *_strchr(const char *str, char c);
char *_strcat(char *dest, const char *src);
int _strncmp(char *str1, char *str2, int count);

char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
char *_strdup(char *str);

int _printerror(char *cmd, char *argv, int count);
void print_number(unsigned int n);
void print_number_in(int n);

int display_history(void);
int print_echo(char **cmd);

char *_itoa(int num);
int _free(char **args);

int builtincmd(char *cmds);
char *getinput(void);

char **tokenizer(char *lineptr, char *delim);
int execute(char **cmds, char **argv, int count);

int _isalpha(int c);
int _atoi(char *s);

void read_file(char *filename, char **argv);
void treat_file(char *line, int counter, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

#endif /* MAIN_H */
