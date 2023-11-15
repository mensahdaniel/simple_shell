#include "main.h"

/**
 * execute- execute specific command by calling fork to start child process
 *
 * @args: array of commnd and arguments
 * @argv: array of program name
 * Return: 0
 */
int execute(char **args, char **argv)
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
		exeerr = execve(args[0], arg, NULL);
		if (exeerr == -1)
		{
			printstr(argv[0]);
			perror(": Not Found");
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
