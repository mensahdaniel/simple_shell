#include "main.h"

/**
 * builtincmd - used to execute builtin functions
 *
 * @cmds: built in command to run
 * Return: -1 if built-in command not found
 */
int builtincmd(char **cmds)
{
	if (_strcmp(cmds[0], "exit") == 0)
	{

		printstr("Exiting...");
		exit(EXIT_FAILURE);
	}

	return (-1);
}
