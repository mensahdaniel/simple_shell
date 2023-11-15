#include "main.h"

int execute(char **argv)
{
	int exeerr;
	char *cmd;
	pid_t pid;

	cmd = get_cmdpath("PATH=");

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		exeerr = execve(argv[1], argv, NULL);
		if (exeerr == -1)
		{
			printstr(argv[0]);
			perror(":Not Found");
		}
	}
	else
	{
		wait(NULL);
	}

	printstr(cmd);

	return (0);
}
