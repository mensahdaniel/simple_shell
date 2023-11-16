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

	cmd = get_cmdpath(cmds[0]);

	if (cmd == NULL)
	{
		// Handle command not found
		if (builtincmd(cmds[0]) == -1)
		{
			printstr(argv[0]);
			printstr(cmds[0]);
			printstr(": Command not found\n");
		}
	}
	else
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(cmd); // Free cmd in case of fork failure
			return 1;
		}
		else if (pid == 0)
		{
			exeerr = execve(cmd, cmds, envp);

			if (exeerr == -1)
			{
				printstr(argv[0]);
				printstr(cmds[0]);
				perror(":");
				free(cmd); // Free cmd if execve fails
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(cmd);
	return 0;
}
