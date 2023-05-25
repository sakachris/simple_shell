#include "shell.h"

/**
 * built_in - executes exit command
 * @cmd: list of commands
 * @str: user input
 *
 * Return: Nothing
 */

void built_in(char **cmd, char *str)
{
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free_malloc(cmd);
		free(str);
		exit(EXIT_SUCCESS);
	}
}

/**
 * print_env - prints environment
 * @cmd: commands
 *
 * Return: Nothing
 */

void print_env(char **cmd)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
	free_malloc(cmd);

}
