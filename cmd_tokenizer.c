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
	char *command;
	/* Allocate memory for tokens dynamically */
	char **tokens = malloc(BUFSIZE * sizeof(char *));

	if (tokens == NULL)
	{
		/* Handle allocation failure */
		return (NULL);
	}

	int i = 0;

	command = _strtok(buffer, delim);
	while (command != NULL)
	{
		tokens[i++] = _strdup(command); /* Allocate memory for each token */
		command = _strtok(NULL, delim);
	}

	tokens[i] = NULL;
	return (tokens);
}
