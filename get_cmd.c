#include "main.h"

/**
 * get_cmdpath - the absolute path of a command
 *
 * @command: The command to be searched for
 * Return: char* The absolute path of the command
 */
char *get_cmdpath(char *command)
{
	char *cmdpath = NULL, *dir = NULL, *cmdp = NULL, *delim = ":";

	cmdpath = get_path("PATH=");

	if (cmdpath == NULL)
	{
		return NULL;
	}

	dir = strtok(cmdpath, delim);
	while (dir != NULL)
	{
		cmdp = malloc(sizeof(char *) * (strlen(command) + strlen(dir) + 2));
		if (cmdp == NULL)
		{
			// Handle allocation failure
			free(cmdpath); // Free cmdpath before returning NULL
			return NULL;
		}
		strcpy(cmdp, dir);
		strcat(cmdp, "/");
		strcat(cmdp, command);

		if (access(cmdp, X_OK) == 0)
		{
			free(cmdpath); // Free cmdpath before returning cmdp
			return cmdp;
		}

		free(cmdp); // Free cmdp if access fails
		dir = strtok(NULL, delim);
	}

	free(cmdpath); // Free cmdpath if command not found
	return NULL;
}
