#include "main.h"

/**
 * _strlen - Get the length of a string
 *
 * @str: The string to get the length of
 * Return: int, the length of the string
 */
unsigned int long _strlen(char *str)
{
	unsigned int long i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
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
 * _strcat - Concatenate two strings
 *
 * @dest: The destination string
 * @src: The source string to be concatenated
 * Return: char* The full concatenated string
 */
char *_strcat(char *dest, char *src)
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
const char *_strchr(const char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return (str + i);
		}
	}
	return (NULL);
}
