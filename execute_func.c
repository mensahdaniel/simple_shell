#include "main.h"

/**
 * run_builtin_func - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int run_builtin_func(char **cmd, int er)
{
	builtin_t bil[] = {{"cd", change_dir},	{"env", display_env},					{"help", display_help},
										 {"echo", echo_func}, {"history", display_history}, {NULL, NULL}};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->function(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * v - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int c(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			get_cmdpath(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * handle_signal - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
