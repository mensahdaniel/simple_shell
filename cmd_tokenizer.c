#include "main.h"

/**
 * tokenizer - breaks the lineptr into tokens based on the specidifed delimiter
 *
 * @buffer: string to be tokenized
 * @delim: the delimiter to be used to tokenize the string
 * Return: the tokenized string as an array of tokens (cmds)
 */
char **tokenizer(char *buffer, char *delim)
{
	int i;
	char *command, /**tokens,*/ *args[SIZE] = {NULL, NULL};

	command = _strtok(buffer, delim);
	i = 0;
	/*tokens = args;*/
	while (command != NULL)
	{
		args[i] = command;
		command = _strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;

	return (args);
}
