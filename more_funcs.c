#include "main.h"

char *_itoa(int num)
{
	int temp = num, n_digits = 0;
	int isNegative = 0;

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

	char *str = malloc((n_digits + isNegative + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (isNegative)
		str[0] = '-';

	str[n_digits + isNegative] = '\0';

	do
	{
		str[--n_digits + isNegative] = (num % 10) + '0';
		num /= 10;
	} while (num != 0);

	return (str);
}
