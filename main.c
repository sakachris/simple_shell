#include "shell.h"

/**
 * sigint_handler - handles SIGINT
 * @sigint_code: value of SIGINT
 *
 * Return: Nothing
 */

void sigint_handler(int sigint_code)
{
	(void)sigint_code;
	_putchar('\n');
	_puts("($) ");
}

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: list of arguments
 *
 * Return: Always 0 on success
 */

int main(int ac, char **av)
{
	char *user_input = NULL;
	ssize_t c_read;
	size_t n;


	(void)ac;
	(void)av;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO))
		{
			_puts("($) ");
		}
		c_read = getline(&user_input, &n, stdin);
		if (c_read == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(user_input);
			exit(EXIT_FAILURE);
		}
		if (user_input[0] == '\n')
		{
			continue;
		}
		central(user_input);
	}
	free(user_input);

	return (0);
}
