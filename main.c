#include "main.h"

/**
 * main - Recreation of a "sh"
 *
 * Return: 0 If succeed, or the number of the error
 */
int main(void)
{
	size_t i = 0;
	int counter = 0, builtIn = 0, status = 0, exitValue = 0, child_pid = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;
	alias_t *aliases = NULL;

	while (1)
	{
		_isattyAndSignal();
		counter = getline(&buffer, &i, stdin);
		if (counter == -1)
			free_and_exit(buffer);
		if (_checkChars(buffer) == -1)
			continue;
		/*Check for alias commands separately */
		if (handle_alias_command(buffer, &aliases) == 1)
			continue;
		buffer = clearBuffer(buffer, counter);
		builtIn = _checkBuiltIn(buffer);

		if (builtIn == 1)
		{
			exitValue = getReturnValue(buffer);
			if (exitValue >= 0)
				break;
			continue;
		}
		else
		{
			if (execute(builtIn, buffer, dup, argv, aliases) == -1)
				break;
		}
	}
	if (builtIn != 1)
		free_array_dup(argv, dup);
	free_aliases(aliases);
	free_buff_and_env(buffer);
	return (exitValue);
}
