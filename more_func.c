#include "main.h"

/**
 * history_dis - Display History Of User Input Simple Shell
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int display_history(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	char *filename = ".shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (-1);

	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}

	if (line)
		free(line);

	fclose(fp);
	return (0);
}

/**
 * _isalpha - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);

	else
		return (0);
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
/**
 * _itoa - converts an integer to a string
 *
 * @num: integer to be converted
 * Return: pointer to the string
 */
char *_itoa(size_t num)
{
	int i = 0, isNegative = 0;
	char *str = (char *)malloc(12 * sizeof(char));

	if (str == NULL)
		exit(1);
	/* Handle negative numbers */
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	/* Process individual digits */
	while (num != 0)
	{
		str[i++] = num % 10 + '0'; /* Convert digit to character */
		num = num / 10;
	}
	/*Add '-' for negative numbers */
	if (isNegative)
		str[i++] = '-';
	/*If the number is 0 */
	if (i == 0)
		str[i++] = '0';
	str[i] = '\0'; /* Adding a null terminator*/

	/* Reverse the string */
	int start = 0, end = i - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return (str);
}
