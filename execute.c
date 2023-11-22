#include "main.h"

int execute(char *buffer, int builtIn, alias_t *aliases)
{
	pid_t child_pid;
	int status = 0;
	char *dup = NULL, **argv = NULL;

	dup = _strdup(buffer);
	argv = tokenizer(dup, builtIn);
	char *alias_value = get_alias(aliases, argv[0]);
	if (alias_value != NULL)
	{
		// If the command matches an alias, execute the alias value as a command
		free_array_dup(argv, dup);
		argv = tokenizer(alias_value, 0);
		builtIn = _checkBuiltIn(alias_value); // Check if it's a built-in command

		// Execute the alias value
		child_pid = child_fork(child_pid, argv[0]);
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}
	else
	{
		/* If not an alias, execute the command normally*/
		child_pid = child_fork(child_pid, argv[0]);
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}
	if (child_pid != 0)
	{
		waitAndFree(status, argv, dup);
	}
	if (builtIn != 1)
		free_array_dup(argv, dup);
}
