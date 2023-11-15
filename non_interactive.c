#include "main.h"

/**
 * non_interactive_mode - handle the non-interactive mode
 */
void non_interactive_mode(void)
{
	char *u_input = NULL;
	size_t buf;
	ssize_t read;

	while ((read = getline(&u_input, &buf, stdin)) != -1)
	{
		char *new_u_input = strndup(u_input, read - 1);

		exec(new_u_input);
		free(new_u_input);
	}
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(u_input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(u_input);
			perror("non interactive");
			exit(EXIT_FAILURE);
		}
	}
	free(u_input);
}
