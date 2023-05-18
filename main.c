#include "shell.h"

int main(void)
{
	char *en;

	en = _getenv("PATH");

	printf("%s\n", en);
	return (0);
}
