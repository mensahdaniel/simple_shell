#include "main.h"

void _free(char **args)
{
	int i = 0;
	while (args[i] != NULL)
		free(args[i++]);
}
