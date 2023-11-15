#include "main.h"
#include <sys/types.h>

/**
 * main - Entry point
 * @ac: The number of arguments
 * @argv: The arguments passed to the program
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	int i;
	char *lineptr, *command;

	size_t n_size;
	ssize_t n_chars;

	(void)ac;
	while (1)
	{
		printstr("(HSH)>>$ ");

		n_chars = getline(&lineptr, &n_size, stdin);

		if (n_chars == -1)
		{
			printstr("\nExiting...");
			exit(EXIT_FAILURE);
		}

		for (i = 0; lineptr[i] != '\n'; i++)
			;
		lineptr[i] = '\0';

		command = _strtok(lineptr, " ");
		i = 1;
		while (command != NULL)
		{
			argv[i] = command;
			i++;
			command = _strtok(NULL, " ");
		}
		argv[i] = NULL;

		execute(argv);
	}

	return (0);
}
