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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string excluding terminating character
 * @str: string to print
 *
 * Return: count of characters printed
 */

int _puts(const char *str)
{
	int i = 0, count = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			count += 1;
			i++;
		}
	}

	return (count);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference of s1 ans s2 or 0 if equal
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	if (s1[i] == s2[i])
		return (0);

	return (s1[i] - s2[i]);
}
