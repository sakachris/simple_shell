#include "shell.h"

/**
 * prompt - prints prompt message
 *
 * Return: Nothing
 */

void prompt(void)
{
	signal(SIGINT, sigint_handler);
	if (isatty(STDIN_FILENO))
		_puts("($) ");

}

/**
 * cmd_not_found - prints error statement when cmd not found
 * @av: arguments list
 * @counter: commands counter
 * @cmd_list: commands list
 * @paths: path list
 *
 * Return: Nothing
 */

void cmd_not_found(char **av, int counter, char **cmd_list, char **paths)
{
	_puts_err(av[0]);
	_puts_err(": ");
	print_counter(counter);
	_puts_err(": ");
	_puts_err(cmd_list[0]);
	_puts_err(": not found");
	_putchar_err('\n');
	free_malloc(cmd_list);
	free_malloc(paths);
}

/**
 * getline_err - sets new line and exits when getline returns -1
 * @user_input: string entered by user
 *
 * Return: Nothing
 */

void getline_err(char *user_input)
{
	if (isatty(STDIN_FILENO))
		_putchar('\n');
	free(user_input);
	exit(EXIT_SUCCESS);

}
