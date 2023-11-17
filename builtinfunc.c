#include "main.h"
#include <unistd.h>

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
	char *lineptr = malloc(BUFFSIZE), ch = 0;
	ssize_t n_chars;
	int i;

	for (i = 0; ch != EOF && ch != '\n'; i++)
	{
		fflush(stdin);
		n_chars = read(STDIN_FILENO, &ch, 1);
		if (n_chars == 0)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		lineptr[i] = ch;
		if (lineptr[0] == '\n')
		{
			free(lineptr);
			return ("\0");
		}
		if (i >= BUFFSIZE)
		{
			lineptr = realloc(lineptr, BUFFSIZE + 1);
			if (lineptr == NULL)
			{
				return (NULL);
			}
		}
	}
	lineptr[--i] = '\0';
	// hashtag_handle(buff);
	return (lineptr);
}
