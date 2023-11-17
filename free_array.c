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
