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

/**
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
