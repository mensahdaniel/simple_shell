#include "main.h"

/**
 * isatty_handler - check if stdin is a terminal
 */
void isatty_handler(void)
{
	if (isatty(STDIN_FILENO))
	{
		printstr("(HSH)>>$ ");
		fflush(stdout);
	}
}
