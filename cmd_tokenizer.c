#include "main.h"

char **tokenizer(char *lineptr)
{
	int i;
	char *command, **cmds = args;
	for (i = 0; lineptr[i] != '\n'; i++)
		;
	lineptr[i] = '\0';

	command = _strtok(lineptr, " ");
	i = 0;
	while (command != NULL)
	{
		cmds[i] = command;
		command = _strtok(NULL, " ");
		i++;
	}
	cmds[i] = NULL;

	return (cmds);
}
