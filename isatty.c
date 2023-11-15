#include "main.h"

void isatty_handler(void)
{
	if (isatty(STDIN_FILENO))
	{
		printstr("(HSH)>>$ ");
		fflush(stdout);
	}
}
