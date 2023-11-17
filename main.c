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
	int count = 0, i, state;

	(void)ac;

	if (argv[1] != NULL)
		read_file(argv[1], argv, state);
	signal(SIGINT, signal_handler);

	while (1)
	{
		isatty_handler();
		lineptr = getinput();
		char **cmds;

		count++;
		add_history(lineptr);
		for (i = 0; lineptr[i] != '\n'; i++)
			;
		lineptr[i] = '\0';
		cmds = tokenizer(lineptr, " ");
		execute(cmds, argv, count, state);
	}
	free(lineptr); /* Free memory allocated by getline after processing */
	return (0);
}
