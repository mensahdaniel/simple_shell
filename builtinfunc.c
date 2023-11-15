#include "main.h"

int buildincmd(char **cmds)
{
	if (_strcmp(cmds[0], "exit") == 0)
	{

		printstr("Exiting...");
		exit(EXIT_FAILURE);
	}

	return (0);
}
