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
	size_t n_size = 0;
	ssize_t n_chars;
	int i;
	while (1)
	{

		n_chars = read(stdin, &lineptr, n_size);

		if (n_chars == -1)
		{
			free(lineptr); /* Free memory allocated by getline*/
			exit(0);
		}

		for (i = 0; lineptr[i] != '\n'; i++)
			;

		lineptr[i] = '\0';

		while (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;

		if (lineptr[0] == ' ' || lineptr[0] == '\t' || lineptr[0] == '\0')
			continue;
	}
}
