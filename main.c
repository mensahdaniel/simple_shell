#include "main.h"

/**
 * main - Entry point
 * @ac: The number of arguments
 * @argv: The arguments passed to the program
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *lineptr = NULL;
	size_t n_size = 0;
	ssize_t n_chars;
	int i;

	(void)ac;
	while (1)
	{
		isatty_handler();
		n_chars = getline(&lineptr, &n_size, stdin);

		if (n_chars == -1)
		{
			printstr("\nExiting...\n");
			free(lineptr); // Free memory allocated by getline
			exit(EXIT_FAILURE);
		}

		if (_strcmp(lineptr, "") == 0)
			continue;
		for (i = 0; lineptr[i] != '\n'; i++)
			;

		lineptr[i] = '\0';

		char **cmds;
		cmds = tokenizer(lineptr, " ");
		execute(cmds, argv);
	}

	free(lineptr); // Free memory allocated by getline after processing
	return 0;
}
