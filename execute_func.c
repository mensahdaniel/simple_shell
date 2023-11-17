#include "main.h"

/**
 * run_builtin_func - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int run_builtin_func(char **cmd, int er)
{
	bulitin_t builtin[] = {{"cd", change_dir},	{"env", dis_env},					{"help", display_help},
												 {"echo", echo_func}, {"history", dis_history}, {NULL, NULL}};

	int i = 0;

	while ((builtin + i)->command)
	{
		if (_strcmp(cmd[0], (builtin + i)->command) == 0)
			return ((builtin + i)->function(cmd, er));
		i++;
	}
	return (-1);
}
/**
 * execute - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @lineptr: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int execute(char **cmd, char *lineptr, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			get_cmdpath(cmd);

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(lineptr);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}
