#include "main.h"

/**
 * _strlen - Get the length of a string
 *
 * @str: The string to get the length of
 * Return: int, the length of the string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

/**
 * _strcmp - Compares two strings
 *
 * @str1: first string
 * @str2: second string to be compare
 * Return: 0 if equal
 */
int _strcmp(char *str1, char *str2)
{
	int def = 0, i, len1, len2;

	len1 = (int)_strlen(str1);
	len2 = (int)_strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			def = str1[i] - str2[i];
			return (def);
		}
		else
			continue;
	}
	return (def);
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
