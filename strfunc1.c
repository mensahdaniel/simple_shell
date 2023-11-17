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
 * _strcat - Concatenate two strings
 *
 * @dest: The destination string
 * @src: The source string to be concatenated
 * Return: char* The full concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
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
/**
 * _strncmp - Compare two strings
 *
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 * @count: The number of characters to compare
 * Return: size_t the difference between the two strings and 0 if equal
 */

int _strncmp(char *str1, char *str2, int count)
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
