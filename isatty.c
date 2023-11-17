#include "main.h"

/**
 * isatty_handler - check if stdin is a terminal
 */
void isatty_handler(void)
{
	if (isatty(STDIN_FILENO))
	{
		printstr(PROMPT);
		/* fflush(stdout); */
	}
}

/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		printstr(PROMPT);
	}
}
