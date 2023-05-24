#include "shell.h"

/**
 * testing_path - finds the path of a given command
 * @paths: array of strings of the paths
 * @cmd_list: array of strings of commands passed
 *
 * Return: matching path
 */

char *testing_path(char **paths, char **cmd_list)
{
	struct stat st;
	char *match;
	int i;

	if (stat(cmd_list[0], &st) == 0)
	{
		match = cmd_list[0];
		return (match);
	}
	else
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			if (stat(paths[i], &st) == 0)
			{
				match = paths[i];
				return (match);
			}
		}
	}

	return (NULL);
}
