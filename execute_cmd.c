#include "shell.h"

/**
 * execute_cmd - executes valid command
 * @cmd: command path
 * @av: array of commands and flags
 *
 * Return: Nothing
 */

void execute_cmd(char *cmd, char **av)
{
	pid_t child_pid;
	int status;

	if (cmd)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./hsh");
			return;
		}
		else if (child_pid == 0)
		{
			execve(cmd, av, environ);
		}
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
