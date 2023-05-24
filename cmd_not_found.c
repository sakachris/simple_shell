#include "shell.h"

/**
 * cmd_not_found - prints error statement when command is not found
 * @av: arguments list
 * @counter: commands counter
 * @cmd_list: commands lists
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
