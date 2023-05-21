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
int main(int ac __attribute__((unused)), char **av)
{
	char *en, *cmd, *user_input = NULL;
	char **cmd_list, **paths;
	ssize_t c_read;
	size_t n;
	int counter = 0;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO))
			_puts("($) ");
		c_read = getline(&user_input, &n, stdin);
		counter++;
		if (c_read == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(user_input);
			exit(EXIT_FAILURE);
		}
		if (user_input[0] == '\n')
			continue;
		cmd_list = tokenize(user_input);
		built_in(cmd_list, user_input);
		en = _getenv("PATH");
		paths = path_list(en, cmd_list[0]);
		cmd = test_path(paths, cmd_list);
		if (cmd != NULL)
			execute(cmd, cmd_list);
		else
		{
			cmd_not_found(av, counter, cmd_list);
			free_malloc(cmd_list);
			free_malloc(paths);
			continue;
		}
		free_malloc(cmd_list);
		free_malloc(paths);
	}
	return (0);
}
