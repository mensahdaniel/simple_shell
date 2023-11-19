#include "main.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *lineptr, **cmd;
	int counter = 0, statue = 1, st = 0, i;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, handle_signal);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		lineptr = _getline();

		while (lineptr[0] == ' ' || lineptr[0] == '\t')
			lineptr++;
		if (lineptr[0] == '\0')
			continue;

		add_history(lineptr);

		for (i = 0; lineptr[i] != '\n'; i++)
			;
		lineptr[i] = '\0';

		cmd = tokenizer(lineptr);
		if (_strcmp(cmd[0], "exit") == 0)
			exit_func(cmd, lineptr, argv, counter);
		else if (check_builtin_func(cmd) == 0)
		{
			st = run_builtin_func(cmd, st);
			_free(cmd, lineptr);
			continue;
		}
		else
			st = execute(cmd, lineptr, counter, argv);
		_free(cmd, lineptr);
	}
	return (statue);
}
/**
 * check_builtin_func - check builtin functions if it exist
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin_func(char **cmd)
{
	builtin_t fun[] = {{"cd", NULL}, {"help", NULL}, {"echo", NULL}, {"history", NULL}, {NULL, NULL}};
	int i = 0;

	if (*cmd == NULL)
		return (-1);

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
