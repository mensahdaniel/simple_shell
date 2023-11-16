#include "main.h"

void _free(char **args)
{
	while (*args != NULL)
		free(*args++);
}
