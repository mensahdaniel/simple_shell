#include "main.h"

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL, *cmds = NULL, *cmdp = NULL;
	int i;

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return NULL;
	}

	// cmds = tokenizer(cmdpath, ":");
	cmds = _strtok(cmdpath, ":");

	for (i = 0; cmds != NULL; i++)
	{
		cmdp = malloc(sizeof(char) * (_strlen(command) + _strlen(cmds) + 2));

		if (cmdp == NULL)
		{
			// Handle allocation failure
			return NULL;
		}

		_strcpy(cmdp, cmds);
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
