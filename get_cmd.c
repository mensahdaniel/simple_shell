#include "main.h"

/**
 * get_full_path - tokenize path and concatenates existing
 * command with tokenized directories in path
 *
 * @path: the value for the PATH variable
 * @command: the command to be concatenated to the directories
 * @delim: delimeter to tokenize path with
 * Return: valid command absolute path
 */
char *get_full_path(const char *path, const char *command, const char *delim)
{
	char *cmdpath = NULL;
	const char *dir = path;

	cmdpath = malloc(_strlen(path) + _strlen(command) + 2);

	while (*dir != '\0')
	{
		const char *end = _strchr(dir, *delim);

		if (end == NULL)
			end = dir + _strlen(dir); /* Last path in PATH */

		size_t dir_len = (size_t)end - (size_t)dir;

		_strcpy(cmdpath, dir);
		cmdpath[dir_len] = '\0';

		_strcat(cmdpath, "/");
		_strcat(cmdpath, command);

		if (access(cmdpath, X_OK) == 0)
		{
			return (cmdpath);
		}

		if (*end == '\0')
		{
			break;
		}

		dir = end + 1; /* Move to the next directory in PATH */
	}
	return (NULL);
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
		return (NULL);
	}

	cmdpath = get_full_path(path, command, delim);
	if (cmdpath)
		return (cmdpath);

	free(cmdpath);
	return (NULL); /* if Command not found */
}
