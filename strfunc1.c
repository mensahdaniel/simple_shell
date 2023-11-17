#include "main.h"
/**
 * _strtok - Tokenize a string based on a specific delimiter
 *
 * @str: The string to tokenize
 * @delim: The delimiter to be used to tokenize the string
 * Return: char* The tokenized string
 */
char *_strtok(char *str, const char *delim)
{
	static char *nextToken = NULL, *tokenStart;

	if (str == NULL && nextToken == NULL)
		return (NULL);

	if (str != NULL)
		nextToken = str;

	while (_strchr(delim, *nextToken) != NULL)
		nextToken++;

	if (*nextToken == '\0')
	{
		nextToken = NULL;
		return (NULL);
	}
	tokenStart = nextToken;

	while (*nextToken != '\0' && _strchr(delim, *nextToken) == NULL)
		nextToken++;

	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}

	return (tokenStart);
}
