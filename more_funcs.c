#include "main.h"

/**
 * _itoa - converts an integer to a string
 *
 * @num: integer to be converted
 * Return: pointer to the string
 */
char *_itoa(int num)
{
	/*Allocating memory for the string*/
	char *str = (char *)malloc(12 * sizeof(char));

	if (str == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	int i = 0;
	int isNegative = 0;

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
	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return str;
}
