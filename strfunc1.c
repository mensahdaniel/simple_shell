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
	char *nextToken = NULL;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL)
		return (NULL);

	char *token = nextToken;

	while (*nextToken != '\0')
	{
		if (_strchr(delim, *nextToken) != NULL)
		{
			*nextToken++ = '\0';
			return (token);
		}
		nextToken++;
	}

	nextToken = NULL;
	return (token);
}

/**
 * _strdup - Duplicate a string
 *
 * @str: The string to be duplicated
 * Return: char* The duplicated string
 */
char *_strdup(char *str)
{
	char *dupstr = NULL;
	int i;

	if (str == NULL)
		return (NULL);

	dupstr = malloc(sizeof(char) * (_strlen(str) + 1));

	if (dupstr == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		dupstr[i] = str[i];

	dupstr[i] = '\0';

	return (dupstr);
}
