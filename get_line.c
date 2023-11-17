
#include "main.h"

/**
 * _getline - Read The Input By User From Stdin
 * Return: Input
 */
char *_getline()
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
	}
	hashtag_handle(lineptr);
	return (lineptr);
}

/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
