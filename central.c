#include "shell.h"

/**
 * central - passes required arguments to other functions
 * @str: input string from user
 *
 * Return: Nothing
 */

void central(char *str)
{
	char **cmd_list, **paths;
	char *en, *cmd;
	int i;

	if (!str)
	{
		/*free(str);*/
		return;
	}
	cmd_list = tokenize(str);
	if (_strcmp(cmd_list[0], "exit") == 0)
	{
		free_malloc(cmd_list);
		free(str);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(cmd_list[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			_puts(environ[i]);
	}
	en = _getenv("PATH");
	paths = path_list(en, cmd_list[0]);
	cmd = test_path(paths, cmd_list);
	execute(cmd, cmd_list);
	free_malloc(cmd_list);
	free_malloc(paths);
}
