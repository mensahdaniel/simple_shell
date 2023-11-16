#include "main.h"

int _free(char **args)
{
	if (*args == NULL)
		return (0);
	while (*args != NULL)
		free(*args++);
}
