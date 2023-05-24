#include "shell.h"

/**
 * cmd_not_found - prints error statement when cmd not found
 * @av: arguments list
 * @counter: commands counter
 * @cmd_list: commands list
 *
 * Return: Nothing
 */

void cmd_not_found(char **av, int counter, char **cmd_list)
{
	_puts_err(av[0]);
	_puts_err(": ");
	print_counter(counter);
	_puts_err(": ");
	_puts_err(cmd_list[0]);
	_puts_err(": not found");
	_putchar('\n');
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
