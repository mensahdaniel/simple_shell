#include "main.h"

/**
 * execute- execute specific command by calling fork to start child process
 *
 * @args: array of arguments
 * Return: 0
 */
int execute(char **args)
{
	int exeerr;
	char *cmd, **arg = NULL;
	pid_t pid;

	cmd = get_cmdpath("PATH=");

	(void)cmd;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		exeerr = execve(args[1], arg, NULL);
		if (exeerr == -1)
		{
			printstr(args[0]);
			perror(":Not Found");
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
