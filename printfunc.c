#include "main.h"

/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */
void printstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return;
}

/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	printstr(argv[0]);
	printstr(": ");
	printstr(er);
	printstr(": ");
	printstr(cmd[0]);
	printstr(": Illegal number: ");
	printstr(cmd[1]);
	printstr("\n");
	free(er);
}
