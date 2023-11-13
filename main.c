#include "main.h"

void prompt()
{
	printf("($) ");
}

int main()
{
	if (isatty(STDIN_FILENO))
	{
	char u_input[1024];

	while (1)
		{
        	prompt();
        	input(u_input, sizeof(u_input));
        	exec(u_input);
		}
	} else {
	non_interactive_mode();
		}
	return 0;
}
