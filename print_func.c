#include "main.h"
#include <stdio.h>

/**
 * _putchar - Write the character c to stdout
 *
 * @c: The character to be printed
 * Return: On success 1. On error, -1 is returned
 */
long int _putchar(char c)
{
	ssize_t num;

	num = (write(STDOUT_FILENO, &c, 1));
	return (num);
}

/**
 * printstr - Print a string to stdout
 *
 * @str: The string to be printed
 * Return: The length of the string
 */
int printstr(char *str)
{
	int i;
	for (i = 0; *str != '\0'; str++, i++)
	{
		_putchar(*str);
	}
	return (i);
}
