#include "main.h"

/**
 * get_cmdpath -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int get_cmdpath(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = get_path("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = add_cmd_path(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * add_cmd_path - Build a full path to the Command
 * @command: Excutable Command
 * @path: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *add_cmd_path(char *command, char *path)
{
	char *cmd;
	size_t len;

	len = _strlen(path) + _strlen(command) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, path);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, command);

	return (cmd);
}
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
		if (_strncmp(env[i], path, 4) == 0)
		{
			pathvar = env[i];

			return (pathvar++ + 6);
		}
	}

	return (NULL);
}

// /**
//  * get_full_path - tokenize path and concatenates existing
//  * command with tokenized directories in path
//  *
//  * @path: the value for the PATH variable
//  * @command: the command to be concatenated to the directories
//  * @delim: delimeter to tokenize path with
//  * Return: valid command absolute path
//  */
// char *get_full_path(const char *path, const char *command, const char *delim)
// {
// 	char *cmdpath = NULL;
// 	const char *dir = path;

// 	cmdpath = malloc(_strlen(path) + _strlen(command) + 2);

// 	while (*dir != '\0')
// 	{
// 		const char *end = _strchr(dir, *delim);

// 		if (end == NULL)
// 			end = dir + _strlen(dir); /* Last path in PATH */

// 		size_t dir_len = (size_t)end - (size_t)dir;

// 		_strcpy(cmdpath, dir);
// 		cmdpath[dir_len] = '\0';

// 		_strcat(cmdpath, "/");
// 		_strcat(cmdpath, command);

// 		if (access(cmdpath, X_OK) == 0)
// 		{
// 			return (cmdpath);
// 		}

// 		if (*end == '\0')
// 		{
// 			break;
// 		}

// 		dir = end + 1; /* Move to the next directory in PATH */
// 	}
// 	return (NULL);
// }
