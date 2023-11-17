#include "main.h"

/**
 * _free - frees an array of strings
 *
 * @args: array of strings
 * Return: 0
 */
int _free(char **args)
{
	if (*args == NULL)
		return (-1);
	while (*args != NULL)
		free(*args++);

	return (0);
}

/**
 * history - Fill File By User Input
 * @input: User Input
 * Return: -1 Fail 0 Succes
 */
int add_history(char *lineptr)
{
	char *filename = ".shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (lineptr)
	{
		len = _strlen(lineptr);

		w = write(fd, lineptr, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
