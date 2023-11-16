#include "main.h"

char *_itoa(int num)
{
	int temp, n_digits = 0;
	int isNegative = 0, dex = 10;
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
			str[dex--] = (temp % 10) + '0';
			temp /= 10;
		}
	}
	return (str);
}
