#include "main.h"

/**
 * input - Check the user input.
 * @u_input: the received user input.
 */
void input(char *u_input, size_t buf)
{
	if(strcmp(u_input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (strcmp(u_input, "env") == 0)
	{
		printEnv();
		exit(EXIT_SUCCESS);
	}
	else if (getline(&u_input, &buf, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(u_input);
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(u_input);
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	u_input[strcspn(u_input, "\n")] = '\0';
}
