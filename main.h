#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFSIZE 1024
/** ENVIRON VARIABLE **/
extern char **environ;

/**
 * struct list_s - lista
 * @str: str
 * @next: next
 */

// typedef struct builtin_s {
//   char *str;
//   struct builtin_s *next;
// } builtin_t;

/* String Functions */
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *str_cat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char delim);
char *_strncpy(char *dest, char *src, int n);
int _atoi(char *s);

void _isattyAndSignal(void);
char *_getenv(const char *name);
void print_env(void);
int _checkChars(char *str);
char *path(char *filename);
int exists(char *path);

int _setenv(char *name, char *value, int overwrite);
int checkUnset(char *str);
int checkSetenv(char *str);
int checkHelp(char *str);
int _unsetenv(char *name);
void handle_signal(int signo);

int checkDir(char *str);
int args(char *str);
void free_buff_and_env(char *str);
int _isdigit(char *str);

int checkExit(char *str);
char *searchAndReplace(char *str);
int checkRoute(char *str);
char *create_variable(char *name, char *value);
char *comments(char *str);
int getReturnValue(char *str);
char *clearBuffer(char *str, int counter);

void helpCase(char *name);

int getLineAndCheck(char *str);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);

void free_environ(char *var_name);
char *searchAndDestroy(char *str);
int itsExecutable(char *str);
int isDir(const char *fileName);

char *addTilde(char *path);

int child_fork(pid_t child_pid, char *name);
int checkEnv(char *str);

void waitAndFree(int status, char **argv, char *dup);
void free_array_dup(char **array, char *dup);
void free_and_exit(char *str);

int _checkBuiltIn(char *str);
char **tokenizer(char *str, int builtIn);

#endif /* MAIN_H */
