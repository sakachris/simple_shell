#include "shell.h"

/**
 * built_in - executes exit and env commands
 * @cmd: list of commands
 * @str: user input
 *
 * Return: Nothing
 */

void built_in(char **cmd, char *str)
{
	int i;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		free_malloc(cmd);
		free(str);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			_puts(environ[i]);
	}
}
