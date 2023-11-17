#include "main.h"
/**
 * add_history - Fill File By User Input
 * @lineptr: User Input
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
		free(env[i]);
}
