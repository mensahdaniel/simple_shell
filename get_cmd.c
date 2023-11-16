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
	char *cmdpath = NULL, **cmds, *cmdp = NULL;
	int i;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return NULL;
	}

	cmds = tokenizer(cmdpath, ":");

	for (i = 0; cmds[i] != NULL; i++)
	{
		printstr(cmds[i]);
		cmdp = malloc(sizeof(char) * (_strlen(command) + _strlen(cmds[i]) + 2));

		if (cmdp == NULL)
		{
			// Handle allocation failure
			return NULL;
		}

		_strcpy(cmdp, cmds[i]);
		_strcat(cmdp, "/");
		_strcat(cmdp, command);

		if (access(cmdp, X_OK) == 0)
		{
			// Free memory allocated for cmds array
			free(cmds);
			return cmdp;
		}

		free(cmdp); // Free cmdp if access fails
	}

	free(cmds); // Free cmds array before returning NULL
	return NULL;
}
