#include "main.h"

/**
 * _strtok - strtok
 * @str: str
 * @delim: delim
 *
 * Return: ret
 */
char *_strtok(char *str, char delim)
{
	static char *tok1, *tok2;
	unsigned int i;

	if (str != NULL)
		tok2 = str;
	tok1 = tok2;
	if (tok1 == NULL)
		return (NULL);
	for (i = 0; tok1[i] != '\0'; i++)
	{
		if (tok1[i] != delim)
			break;
	}
	if (tok2[i] == '\0')
	{
		tok2 = NULL;
		return (NULL);
	}
	tok1 = tok2 + i;
	tok2 = tok1;
	for (i = 0; tok2[i] != '\0'; i++)
	{
		if (tok2[i] == delim)
			break;
	}
	if (tok2[i] == '\0')
		tok2 = NULL;
	else
	{
		tok2[i] = '\0';
		tok2 += i + 1;
		if (tok2[0] == '\0')
			tok2 = NULL;
	}
	return (tok1);
}
/**
 * _strlen - Calculates the length of a string
 * @s: String
 *
 * Return: Returns the length of a string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
/**
 * _strdup - Duplicate a string
 *
 * @str: The string to be duplicated
 * Return: char* The duplicated string
 */
char *_strdup(const char *str)
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

/**
 * _strncmp - Compare two strings
 *
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 * @count: The number of characters to compare
 * Return: size_t the difference between the two strings and 0 if equal
 */

int _strncmp(char *str1, char *str2, size_t count)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	for (i = 0; i < count && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: Destination string
 * @src: Source string
 * Return: Returns the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strchr - Find the first occurrence of a character in a string
 *
 * @str: The string to be searched
 * @c: The character to search for
 * Return: char* The pointer to the first occurrence of the character
 */
char *_strchr(const char *str, char c)
{
	for (; *str != '\0'; str++)
	{
		if (*str == c)
		{
			return ((char *)(str));
		}
	}
	return (NULL);
}
