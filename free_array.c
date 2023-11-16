#include "main.h"

int _free(char **args)
{
	if (*args == NULL)
		return (-1);
	while (*args != NULL)
		free(*args++);

	return (0);
}
