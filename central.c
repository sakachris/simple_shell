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

	if (!str)
	{
		/*free(str);*/
		return;
	}
	cmd_list = tokenize(str);
	en = _getenv("PATH");
	paths = path_list(en, cmd_list[0]);
	cmd = test_path(paths, cmd_list);
	execute(cmd, cmd_list);
	free_malloc(cmd_list);
	free_malloc(paths);
}
