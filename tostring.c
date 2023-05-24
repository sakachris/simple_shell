#include "shell.h"

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar_err(char c)
{
	return (write(2, &c, 1));
}

/**
 * print_counter - converts int to string & prints to stderr
 * @num: integer to convert and print
 *
 * Return: Nothing
 */

void print_counter(int num)
{
	unsigned int i, j = 1;
	unsigned int v, v1, v2 = 1;

	v1 = num;
	while (v1 > 9)
	{
		v1 = v1 / 10;
		v2 = v2 * 10;
		j++;
	}

	for (i = 1; i <= j; i++)
	{
		v = num / v2;
		num = num % v2;
		v2 = v2 / 10;
		_putchar_err(v + '0');
	}
}
