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
		strcpy(cmdp, dir);
		strcat(cmdp, "/");
		strcat(cmdp, command);

		printf("full path: %s\n", cmdp);
		if (access(cmdp, X_OK) == 0)
			return (cmdp);
		dir = strtok(NULL, delim);
		printf("token path: %s\n", dir);
	}

	return (NULL);
}
