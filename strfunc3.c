#include "main.h"

/**
 * _strcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
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
