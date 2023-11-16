#include "main.h"

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL, **cmds = NULL, *cmdp = NULL;
	int i;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return NULL;
	}

	cmdp = full_path(command, cmdpath);

	return (cmdp);
}
