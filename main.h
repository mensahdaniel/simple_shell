#ifndef MAIN_H
#define MAIN_H

/**###### C HEADER LIBRARIES USED ######*/

#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**###### environ var ######*/

extern char **environ;

/**##### DEFINED MACROS ######*/

#define SIZE 50
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "(HSH)>>$ "
#define PRINT(c) (write(STDOUT_FILENO, &c, _strlen(c)))

/**###### STRING FUNCTION ######*/

char *_strtok(char *str, const char *tok);
char *_strncpy(char *dest, char *src, unsigned long int n);
size_t _strlen(const char *str);
int _putchar(char c);
int _atoi(char *str);
void printstr(char *str);
int _strcmp(char *str1, char *str2);
int _isalpha(int c);
char *_itoa(size_t num);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(const char *str, char c);
int _strncmp(char *str1, char *str2, size_t count);
char *_strdup(char *str);

/**###### MEMORY  MANGMENT FUNCTIONS ####*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free(char **cmd, char *line);

/**###### INPUT Function ######*/

void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);

/** ###### Command parser and extractor ###*/

int get_cmdpath(char **line);
char *get_path(char *path);
char **tokenizer(char *buffer, char *delim);
int run_builtin_func(char **cmd, int er);
void read_file(char *filename, char **argv);
char *add_cmd_path(char *command, char *path);
int check_builtin_func(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** ####BUL FUNC #####*/

void hashtag_handle(char *buff);
int add_history(char *input);
int display_history(char **cmd, int er);
int display_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo(char **cmd, int er);
void exit_func(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** ####error handle and Printer ####*/
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct bulltin {
  char *command;
  int (*function)(char **line, int er);
} bul_t;

#endif /* MAIN_H */
