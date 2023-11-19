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
		cmd_path = add_fullpath(*cmd, value);
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
 * add_fullpath - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *add_fullpath(char *command, char *directory)
{
	char *cmd;
	size_t len;

	len = _strlen(directory) + _strlen(command) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, directory);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, command);

	return (cmd);
}
/**
 * get_path - Gets The Value Of Enviroment Variable By Name
 * @var_name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *get_path(char *var_name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlen(var_name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var_name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
