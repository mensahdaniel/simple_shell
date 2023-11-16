#include "main.h"

char *_itoa(int num)
{
	int temp = num, n_digits = 0;
	int isNegative = 0, dex;
	char *str = (char *)malloc(12 * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (num < 0)
	{
		temp = -temp;
		str[0] = '-';
	}
	else
	{
	}

	while (temp != 0)
	{
		n_digits++;
		temp /= 10;
	}

	return (str);
}
