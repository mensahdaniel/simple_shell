#include "main.h"
#include <stdlib.h>
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
	cmd = malloc(_strlen(command) + 100 + 2);

	for (i = 0; cmds[i]; i++)
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
