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
	char *cmdpath = NULL, **cmds, *cmdp;
	int i;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return (NULL);
	}

	cmds = tokenizer(cmdpath, ":");
	cmdp = malloc(sizeof(char) * (_strlen(command) + _strlen(cmds[0]) + 2));

	for (i = 0; cmds[i]; i++)
	{
		_strcpy(cmdp, cmds[i]);
		_strcat(cmdp, "/");
		_strcat(cmdp, command);
		_strcat(cmdp, "\0");

		if (access(cmdp, X_OK))
			return (cmdp);
	}

	return (NULL);
}
