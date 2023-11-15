#include "main.h"

/**
 * main - Entry point
 * @ac: The number of arguments
 * @argv: The arguments passed to the program
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	int i, new;
	char *lineptr /*command,*args[256] = {NULL, NULL}*/;
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
		for (i = 0; lineptr[i] != '\n'; i++)
			;
		lineptr[i] = '\0';

		new = execve(lineptr, argv, NULL);
		if (new == -1)
		{
			printstr(argv[0]);
			perror(": Not Found");
		}
		/*execute(args); */
	}

	return (0);
}
