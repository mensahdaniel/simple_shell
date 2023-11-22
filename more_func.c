#include "main.h"

/**
 * _isattyAndSignal - Looks for signals and checks the isatty function
 */
void _isattyAndSignal(void)
{
	signal(SIGINT, handle_signal);
	if ((isatty(STDIN_FILENO) == 1))
		write(STDOUT_FILENO, "(HSH)>>$ ", 9);
}
/**
 * clearBuffer - Removes the '\n' char, and looks for tabulations
 * @str: The buffer
 * @counter: Length of the string
 *
 * Return: The clean buffer
 */
char *clearBuffer(char *str, int counter)
{
	str[counter - 1] = '\0';
	str = searchAndDestroy(str);
	str = comments(str);
	return (str);
}

/**
 * comments - Checks for comments
 * @str: String to traverse
 *
 * Return: The clean string in case of comments, if not, the same one
 */
char *comments(char *str)
{
	int i = 0, j = 0, hashtag = 0, flag = 0;

	while (str[j])
	{
		if (str[j] == ' ' && str[j + 1] == '#')
		{
			hashtag++;
			break;
		}
		j++;
	}
	if (hashtag == 0)
		return (str);
	while (str[i])
	{
		if (flag == 1)
		{
			str[i] = ' ';
			i++;
			continue;
		}
		if (str[i] == ' ' && str[i + 1] == '#')
		{
			flag++;
			i++;
			continue;
		}
		i++;
	}
	return (str);
}
/**
 * searchAndDestroy - Looks for a tabulation and erases it
 * @str: String to traverse
 *
 * Return: The modified string or just the string
 */
char *searchAndDestroy(char *str)
{
	int i = 0, tab = 0;

	while (str[i])
	{
		if (str[i] == '\t')
		{
			tab++;
		}
		i++;
	}
	i = 0;
	if (tab > 0)
	{
		while (str[i])
		{
			if (str[i] == '\t')
			{
				str[i] = ' ';
			}
			i++;
		}
	}
	return (str);
}

/**
 * _atoi - converts string to an integer
 * @s: string
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	char c;
	unsigned int i, n = 0, j = _strlen(s) - 1, null = -1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = s[i];
		if (c == '-')
			sign *= -1;
		if (c >= 48 && c <= 57)
		{
			n = n * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c >= 48 && c <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (j == null)
		return (0);
	return (n);
}

/**
 * _perror -
 *
 * @args: argument vector name
 * @cmd: input name
 * @count: program execution count
 * Return: 0 on success
 */
int _perror(char **args, char *cmd, int count)
{
	char *num = _itoa(count);

	PRINT(args[0]);
	PRINT(": ");
	PRINT(num);
	PRINT(cmd);
	PRINT(": not found");
	return (0);
}
