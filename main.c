#include "main.h"

/**
 * main - Entry point
 * @ac: The number of arguments
 * @argv: The arguments passed to the program
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *lineptr = malloc(BUFFSIZE);
	size_t n_size = 0;
	ssize_t n_chars;
	int i, count = 0;

	(void)ac;
	while (1)
	{
		isatty_handler();

		char **cmds;

		count++;

		cmds = tokenizer(lineptr, " ");
		execute(cmds, argv, count);
	}
	free(lineptr); /* Free memory allocated by getline after processing */
	return (0);
}
