#include "main.h"

/**
 * handle_signal - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		PRINT(PROMPT);
	}
}
