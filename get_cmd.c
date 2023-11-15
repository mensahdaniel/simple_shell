#include "main.h"
#include <unistd.h>

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL, **cmds = NULL, *cmd;
	int i;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return (NULL);
	}

	cmds = tokenizer(cmdpath, ":");
	for (i = 0; cmd[i]; i++)
	{
		_strcpy(cmd, cmds[i]);
		_strcat(cmd, "/");
		_strcat(cmd, command);
		_strcat(cmd, "\0");

		if (access(cmd, X_OK))
			return (cmd);
	}

	return (NULL);
}
