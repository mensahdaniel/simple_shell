#include "main.h"

void _free(char **args)
{
	while (*args != NULL)
		if (*args == NULL)
			break;
	free(*args++);
}
