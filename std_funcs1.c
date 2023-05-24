#include "shell.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 *
 * Return: concatenated string to dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcpy - copies a string
 * @src: source string pointer
 * @dest: destination pointer
 *
 * Return: destination
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - finds the size of a string
 * @str: string to find its size
 *
 * Return: size of the string
 */

int _strlen(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str)
	{
		count++;
		str++;
	}

	return (count);
}

/**
 * _strncmp - compares two strings for the first n bytes
 * @str1: first string
 * @str2: second string
 * @n: bytes to compare
 *
 * Return: 0 if equal or less than or greator than 0 if unequal
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	int s1, s2;

	while (*str1 && *str2 && (*str1 == *str2) && n)
	{
		n--;
		str1++;
		str2++;
	}

	s1 = *str1 + '0';
	s2 = *str2 + '0';

	if (n == 0)
	{
		return (0);
	}

	return (s1 - s2);
}

/**
 * word_count - counts the number of words in s string
 * @s: string to count words from
 *
 * Return: number of words in string
 */

int word_count(char *s)
{
	int status = 0;
	int count = 0;

	while (*s)
	{
		if (*s == '\n' || *s == '\t' || *s == ' ' || *s == ':')
			status = 0;
		else if (status == 0)
		{
			status = 1;
			count++;
		}
		s++;
	}

	return (count);
}
