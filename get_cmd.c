#include "main.h"

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL, *cmdp = NULL;
	const char *path = get_path("PATH");
	const char *delim = ":";

	if (path == NULL || command == NULL)
	{
		return NULL;
	}

	size_t path_len = strlen(path);
	cmdpath = malloc(path_len + strlen(command) + 2);

	if (cmdpath == NULL)
	{
		return NULL; /* Handle allocation failure */
	}

	const char *dir = path;
	while (*dir != '\0')
	{
		const char *end = _strchr(dir, *delim);
		if (end == NULL)
		{
			end = dir + _strlen(dir); /* Last path in PATH */
		}

		size_t dir_len = end - dir;
		strncpy(cmdpath, dir, dir_len);
		cmdpath[dir_len] = '\0';

		strcat(cmdpath, "/");
		strcat(cmdpath, command);

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

	free(cmdpath);
	return NULL; /* if Command not found */
}
