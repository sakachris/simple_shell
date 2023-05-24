#include "shell.h"

/**
 * tokenize - splits string by delimeter given
 * @str: string to split
 *
 * Return: array of strings
 */

char **tokenize(char *str)
{
	char **cmd_list = NULL;
	char *token;
	const char *delim = " \n";
	int i, words = word_count(str);

	cmd_list = malloc(sizeof(cmd_list) * (words + 1));
	if (!cmd_list)
	{
		return (NULL);
	}
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		cmd_list[i] = malloc(sizeof(token) * (_strlen(token) + 1));
		_strcpy(cmd_list[i], token);
		token = strtok(NULL, delim);
	}
	cmd_list[i] = NULL;
	return (cmd_list);

}
