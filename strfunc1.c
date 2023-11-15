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

char *_strcpy(char *dest, char *src)
{
	if (src != NULL)
	{
		dest = src;
	}
	return (dest);
}
