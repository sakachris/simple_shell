#include "shell.h"

/**
 * path_list - gets the path and splits it
 * @path: path to split
 * @cmd: command to test its path
 * Return: array of strings of paths
 */

char **path_list(char *path, char *cmd)
{
	char **paths = NULL;
	char *token, *copy_path, *delim = ":";
	int path_size = _strlen(path) + 1;
	int path_words = word_count(path) + 1;
	int i = 0;

	copy_path = malloc(sizeof(copy_path) * path_size);
	_strcpy(copy_path, path);

	paths = malloc(sizeof(paths) * path_words);

	token = strtok(copy_path, delim);
	while (token != NULL)
	{
		paths[i] = malloc(sizeof(token) * (_strlen(token) + 2));
		_strcpy(paths[i], token);
		_strcat(paths[i], "/");
		_strcat(paths[i], cmd);
		_strcat(paths[i], "\0");
		token = strtok(NULL, delim);
		i++;
	}
	paths[i] = NULL;
	free(copy_path);

	return (paths);
}
