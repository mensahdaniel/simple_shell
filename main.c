#include "main.h"

/**
 * main - Entry point
 * @ac: The number of arguments
 * @argv: The arguments passed to the program
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *lineptr, **cmds;
	size_t n_size;
	ssize_t n_chars;

	(void)ac;
	while (1)
	{
		isatty_handler();
		n_chars = getline(&lineptr, &n_size, stdin);

		if (n_chars == -1)
		{
			printstr("\nExiting...");
			exit(EXIT_FAILURE);
		}
		cmds = tokenizer(lineptr);
		execute(cmds, argv);
	}

	return (0);
}
