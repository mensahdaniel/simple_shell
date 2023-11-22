#include "main.h"

/**
 * main - Recreation of a "sh"
 *
 * Return: 0 If succeed, or the number of the error
 */
int main(int ac, char **argv)
{
	size_t i = 0;
	int counter = 0, builtIn = 0, status = 0, exitValue = 0, n_chars = 0;
	char *buffer = NULL;
	alias_t *aliases = NULL;

	while (1)
	{
		counter++;
		_isattyAndSignal();
		n_chars = getline(&buffer, &i, stdin);
		if (n_chars == -1)
			free_and_exit(buffer);
		if (_checkChars(buffer) == -1)
			continue;
		/*Check for alias commands separately */
		if (handle_alias_command(buffer, &aliases) == 1)
			continue;
		buffer = clearBuffer(buffer, n_chars);
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
			if (execute(argv, buffer, builtIn, aliases, counter) == -1)
				break;
		}
	}
	free_aliases(aliases);
	free_buff_and_env(buffer);
	free_array_dup(argv, dup);
	return (exitValue);
}
