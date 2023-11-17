#include "main.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	printstr("(HSH)>>$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	printstr(argv[0]);
	printstr(": ");
	er = _itoa(counter);
	printstr(er);
	free(er);
	printstr(": ");
	printstr(input);
	printstr(": not found\n");
}
