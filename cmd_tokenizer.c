#include "main.h"

/**
 * tokenizer - breaks the lineptr into tokens based on the specidifed delimiter
 *
 * @buffer:
 */
char **tokenizer(char *buffer, char *delim)
{
	int i;
	char *command, **cmds, *args[SIZE] = {NULL, NULL};

	for (i = 0; buffer[i] != '\n'; i++)
		;
	buffer[i] = '\0';

	command = _strtok(buffer, delim);
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
