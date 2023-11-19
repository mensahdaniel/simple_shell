
#include "main.h"

/**
 * _getline - Read The Input By User From Stdin
 * Return: Input
 */
char *_getline()
{
	int i, buffsize = BUFSIZE, rd;
	char ch = 0;
	char *lineptr = malloc(buffsize);

	if (lineptr == NULL)
	{
		free(lineptr);
		return (NULL);
	}

	for (i = 0; ch != EOF && ch != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &ch, 1);
		if (rd == 0)
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
		if (i >= buffsize)
		{
			lineptr = _realloc(lineptr, buffsize, buffsize + 1);
			if (lineptr == NULL)
			{
				return (NULL);
			}
		}
	}
	lineptr[i - 1] = '\0';
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
