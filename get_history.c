#include "main.h"
/**
 * add_history - store user input in file
 *
 * @lineptr: User Input
 * Return: -1 Fail 0 Succes
 */
int add_history(char *lineptr)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0, i;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);

	for (i = 0; lineptr[i] != '\0'; i++)
		;
	lineptr[i] = '\n';

	if (lineptr)
	{
		while (lineptr[len])
			len++;
		w = write(fd, lineptr, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
