#include "main.h"

/**
 * _putchar - Write the character c to stdout
 *
 * @c: The character to be printed
 * Return: On success 1. On error, -1 is returned
 */
long int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
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

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * _printerror - Print an error message
 *
 * @cmd: The command that was not found
 * @argv: executed shell program name
 * @count: the number of times commands have been executed
 * Return: 0
 */
int _printerror(char *cmd, char *argv, int count)
{
	char *num = _itoa(count);

	printf("%s", argv);
	printf(": ");
	printf("%s", num);
	printf(": ");
	printf("%s", cmd);
	printf(": not found\n");

	return (0);
}
