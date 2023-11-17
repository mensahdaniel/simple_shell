#include "main.h"

/**
 * builtincmd - used to execute builtin functions
 *
 * @cmds: built in command to run
 * Return: -1 if built-in command not found
 */
int builtincmd(char *cmds)
{
	if (_strcmp(cmds, "exit") == 0)
	{

		printstr("Exiting...");
		exit(EXIT_FAILURE);
	}

	return (-1);
}

char *getinput(void)
{
	char *lineptr = malloc(BUFFSIZE);
	int n_chars, i;

	for (i = 0; lineptr[i] != '\n'; i++)
	{
		n_chars = read(stdin, &lineptr[i], 1);
		if (n_chars == 0)
		{
			free(lineptr); /* Free memory allocated by getline*/
			exit(0);
		}

		if (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;

		if (lineptr[0] == ' ' || lineptr[0] == '\t' || lineptr[0] == '\0')
			continue;

		if (i >= BUFFSIZE)
			lineptr = realloc(lineptr, BUFFSIZE + 1);
	}
	lineptr[i] = '\0';
	return (lineptr);
}
