#include "main.h"

char *_itoa(int num)
{
	int temp, dex = 10;
	char *str = (char *)malloc(12 * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (num < 0)
	{
		temp = -num;
		str[0] = '-';
	}
	else
	{
		temp = num;
		str[0] = '\0';
	}

	if (temp == 0)
	{
		str[dex--] = '0';
	}
	else
	{
		while (temp != 0)
		{
			char digit = (char)(temp % 10) + '0';
			str[dex--] = digit;
			temp /= 10;
		}
	}
	return (&str[dex + 1]);
}

char *full_path(char *cmd, char *path)
{
	char *dir, *token, *delim = ":";

	return (NULL);
}
