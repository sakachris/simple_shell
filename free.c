#include "shell.h"

/**
 * free_malloc - free malloc allocated to array of strings
 * @str: array of strings
 * Return: Nothing
 */

void free_malloc(char **str)
{
	char **mem = str;

	if (!str)
	{
		return;
	}
	while (*str)
	{
		free(*str++);
	}
	free(mem);
}
