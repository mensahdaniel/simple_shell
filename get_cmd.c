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
	char *cmdpath = NULL, **cmds, *cmd;
	int i;
	(void)command;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return (NULL);
	}

	cmds = tokenizer(cmdpath, ":");
	for (i = 0; cmd[i]; i++)
	{
		_strcat(cmd, cmds[i]);
	}

	return (cmds[i]);
}
