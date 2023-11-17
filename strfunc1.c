#include "main.h"
/**
 * _strcpy - Copy a string to another
 *
 * @dest: The destination string
 * @src: The source string to be copied
 * Return: char* The copied string
 */
char *_strcpy(char *dest, const char *src)
{
	if (src != NULL)
	{
		int i;

		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (dest);
}
/**
 * _strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
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
	int i;

	for (i = 0; i < count; i++)
	{
		if (str1[i] > str2[i])
		{
			return (str1[i] - str2[i]);
		}
		else if (str1[i] < str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
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
