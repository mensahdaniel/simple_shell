#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, unsigned long int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _atoi - converts a string to an integer
 * @s:the string
 * Return:int
 */
int _atoi(char *str)
{
	int i, j, num, x;

	i = num = 0;
	x = 1;
	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		num = (num * 10) + x * ((str[j]) - '0');
		j++;
	}
	return (num);
}

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
