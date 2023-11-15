#include "main.h"

/**
 * execute- execute specific command by calling fork to start child process
 *
 * @cmds: array of commnd and arguments
 * @argv: array of program name
 * Return: 0
 */
int execute(char **cmds, char **argv)
{
	char **envp = environ;
	int exeerr;
	char *cmd;
	pid_t pid;

	cmd = get_cmdpath("PATH=");

	(void)cmd;

	if (buildincmd(cmds) == -1)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			exeerr = execve(cmds[0], cmds, envp);
			if (exeerr == -1)
			{
				printstr(argv[0]);
				perror(":");
				printstr(cmds[0]);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
