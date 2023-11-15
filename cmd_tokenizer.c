#include "main.h"

/**
 * tokenizer - breaks the lineptr into tokens based on the specidifed delimiter
 */
char **tokenizer(char *lineptr, char *delim)
{
	int i;
	char *command, **cmds, *args[SIZE] = {NULL, NULL};

	for (i = 0; lineptr[i] != '\n'; i++)
		;
	lineptr[i] = '\0';

	command = _strtok(lineptr, delim);
	i = 0;
	cmds = args;
	while (command != NULL)
	{
		cmds[i] = command;
		command = _strtok(NULL, delim);
		i++;
	}
	cmds[i] = NULL;

	return (cmds);
}
