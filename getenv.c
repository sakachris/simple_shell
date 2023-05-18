#include "shell.h"

/**
 * _getenv - gets the environments of the specified type
 * @name: name of the environment
 *
 * Return: environment string
 */

char *_getenv(const char *name)
{
	size_t name_size = _strlen(name);
	char *en = NULL;
	int i = 0;

	while (environ[i])
	{
		if (!_strncmp(name, environ[i], name_size))
			en = environ[i] + name_size + 1;
		i++;
	}
	return (en);
}
