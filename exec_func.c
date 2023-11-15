#include "main.h"

/**
 * execute- execute specific command by calling fork to start child process
 *
 * @argv: array of arguments
 */
int execute(char **args)
{
	int exeerr;
	char *cmd;
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
		exeerr = execve(args[1], NULL, NULL);
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
