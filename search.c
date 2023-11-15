#include "main.h"

/**
 * search - function to find path of commands.
 * @tmp_cmd: input string command.
 * Return: pointer to command
 */
char *search(char *tmp_cmd)
{
	struct stat b;
	size_t len = 1024;
	char *oldPth, *oldPth_dup, *token, *newPth;

	oldPth = getenv("PATH");
	if (oldPth != NULL)
	{
		oldPth_dup = strdup(oldPth);
		token = strtok(oldPth_dup, ":");
		while (token != NULL)
		{
			newPth = malloc(sizeof(char *) * 1024);
			if (newPth == NULL)
			{
				free(newPth);
				return (NULL);
			}
			strncpy(newPth, token, len - 1);
			newPth[len - 1] = '\0';
			strncat(newPth, "/", len - strlen(newPth) - 1);
			strncat(newPth, tmp_cmd, len - strlen(newPth) - 1);
			if (stat(newPth, &b) == 0)
			{
				free(oldPth_dup);
				return (newPth);
			}
			token = strtok(NULL, ":");
		}
		free(oldPth_dup);
	}
	if (stat(tmp_cmd, &b) == 0)
	{
		return (tmp_cmd);
	}
	free(newPth);
	return (NULL);
}
