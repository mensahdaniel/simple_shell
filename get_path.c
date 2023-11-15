#include "main.h"

/**
 * get_path - Get the PATH environment variable
 *
 * @path: The PATH environment variable name
 * Return: char* The content of the PATH environment variable
 */
char *get_path(char *path)
{
	char *pathvar, **env = environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], path, 5) == 0)
		{
			pathvar = env[i];

			return (pathvar++ + 5);
		}
	}

	return (NULL);
}
