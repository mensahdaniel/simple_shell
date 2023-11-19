#include "main.h"

/**
 * handle_signal - Signal handler for ^C
 * @sig: Signal number
 */
void handle_signal(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n(HSH)>>$ ", 9);
}

/**
 * args - Counts all the possibles arguments of a function
 * @str: String to traverse
 *
 * Return: The possibles arguments
 */
int args(char *str)
{
	int i = 1, counter = 0;

	if (str[0] != ' ')
		counter++;
	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		counter++;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}
