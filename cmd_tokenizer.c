#include "main.h"

/**
 * tokenizer - Parse Line Of Input
 * @lineptr:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **tokenizer(char *lineptr)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFFSIZE;

	if (lineptr == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(lineptr, "\n ");

	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
