#include "main.h"

char *add_path(char *cmdpath, const char *path, const char *command, const char *delim)
{
	const char *dir = path;
	while (*dir != '\0')
	{
		const char *end = _strchr(dir, *delim);
		if (end == NULL)
		{
			end = dir + _strlen(dir); /* Last path in PATH */
		}

		size_t dir_len = (size_t)end - (size_t)dir;
		_strcpy(cmdpath, dir);
		cmdpath[dir_len] = '\0';

		_strcat(cmdpath, "/");
		_strcat(cmdpath, command);

		if (access(cmdpath, X_OK) == 0)
		{
			return cmdpath;
		}

		if (*end == '\0')
		{
			break;
		}

		dir = end + 1; /* Move to the next directory in PATH */
	}
}

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL;
	const char *path = get_path("PATH");
	const char *delim = ":";

	if (path == NULL || command == NULL)
	{
		return NULL;
	}

	size_t path_len = _strlen(path);
	cmdpath = malloc(path_len + strlen(command) + 2);

	if (cmdpath == NULL)
	{
		return NULL; /* Handle allocation failure */
	}

	cmdpath = add_path(cmdpath, path);
	free(cmdpath);
	return NULL; /* if Command not found */
}
