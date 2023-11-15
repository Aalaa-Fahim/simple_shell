#include "main.h"

/**
 * search - function to find path of commands.
 * @tmp_cmd: input string command.
 * Return: pointer to command
 */
char *search(char *tmp_cmd)
{
	struct stat b;
	char *oldPth, *oldPth_dup, *token, *newPth;

	oldPth = getenv("PATH");
	if (oldPth)
	{
		oldPth_dup = strdup(oldPth);
		token = strtok(oldPth_dup, ":");
		while (token != NULL)
		{
			newPth = malloc(sizeof(char *) * 1024);
			strcpy(newPth, token);
			strcat(newPth, "/");
			strcat(newPth, tmp_cmd);
			strcat(newPth, "\0");
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
