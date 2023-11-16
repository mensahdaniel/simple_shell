#include "main.h"

char *_itoa(int num)
{
	int temp = num, n_digits = 0;
	int isNegative = 0, dex;

	if (num < 0)
	{
		isNegative = 1;
		temp = -temp;
	}

	while (temp != 0)
	{
		n_digits++;
		temp /= 10;
	}

	char *str = (char *)malloc((n_digits + isNegative + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (isNegative)
		str[0] = '-';

	dex = n_digits + isNegative;
	str[dex] = '\0';

	while (n_digits != 0)
	{
		str[--dex] = (num % 10) + '0';
		num /= 10;
		n_digits--;
	}

	return (str);
}
