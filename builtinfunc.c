#include "main.h"

/**
 * builtincmd - used to execute builtin functions
 *
 * @cmds: built in command to run
 * Return: -1 if built-in command not found
 */
int builtincmd(char **cmds, int state)
{
	if (_strcmp(cmds[0], "exit") == 0)
	{
		printstr("Exiting...");
		exit(EXIT_FAILURE);
	}
	else if (_strcmp(cmds[0], "cd") == 0)
		return (change_dir(cmds));
	else if (_strcmp(cmds[0], "env") == 0)
		display_env();
	else if (_strcmp(cmds[0], "echo") == 0)
		return (echo(cmds, state));

	return (-1);
}

/**
 * getinput - read input from file stream
 *
 * Return: the string of characters read with a null terminator.
 */
char *getinput(void)
{
	char *lineptr = malloc(BUFFSIZE), ch = 0;
	ssize_t n_chars;
	int i;

	for (i = 0; lineptr[i - 1] != EOF && lineptr[i - 1] != '\n'; i++)
	{
		fflush(stdin);
		n_chars = read(STDIN_FILENO, &lineptr[i], 1);

		if (n_chars == 0)
		{
			free(lineptr); /* Free memory allocated by getline*/
			exit(EXIT_SUCCESS);
		}

		if (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;
	}
	// hashtag_handle(buff);
	return (lineptr);
}
