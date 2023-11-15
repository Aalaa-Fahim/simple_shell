#include "main.h"

/**
 * prompt - function to print prompt.
 */
void prompt(void)
{
	printf("($) ");
}

/**
 * main - entry point to code simple shell.
 * Return: 0 if success.
 */
int main(void)
{
	char u_input[100];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			prompt();
				if (fgets(u_input, sizeof(u_input), stdin) == NULL)
				break;
			u_input[strcspn(u_input, "\n")] = '\0';
				if (strlen(u_input) == 0)
				continue;
			exec(u_input);
		}
	} 
	else
	{
		non_interactive_mode();
	}
	return (0);
}
