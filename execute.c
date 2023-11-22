#include "main.h"

/**
 * execute - execute commands
 *
 * @buffer: user input
 * @builtin: integer
 * @aliases: aliases list
 * Return: success 0
 */
int execute(char **args, char *buffer, int builtin, alias_t *aliases, int count)
{
	int status = 0, child_pid = 0;
	char *dup = NULL, **argv = NULL;

	dup = _strdup(buffer);
	argv = tokenizer(dup, builtin);
	char *alias_value = get_alias(aliases, argv[0]);

	if (alias_value != NULL)
	{
		/* If the command matches an alias, execute the alias value as a command*/
		free_array_dup(argv, dup);
		argv = tokenizer(alias_value, 0);
		builtin = _checkBuiltIn(alias_value); /* Check if it's a built-in command*/

		/* Execute the alias value */
		child_pid = child_fork(child_pid, argv[0]);
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			_perror(args, argv[0], count);
			free_array_dup(argv, dup);
			return (-1);
		}
	}
	else
	{
		/* If not an alias, execute the command normally*/
		child_pid = child_fork(child_pid, argv[0]);
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			_perror(args, argv[0], count);
			free_array_dup(argv, dup);
			return (-1);
		}
	}
	if (child_pid != 0)
		waitAndFree(status, argv, dup);

	return (0);
}
