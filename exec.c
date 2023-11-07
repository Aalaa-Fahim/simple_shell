#include "main.h"
/**
 * exec - function to execute input.
 * @inputStr: input.
 * Return: void function.
*/
void exec(char *inputStr)
{
	char *argv[1024];
	int status, argv_counter = 0;
	char *text;
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		ARprint("Error:\n");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		text = strtok((char *)inputStr, " ");
		while (text != NULL)
		{
			argv[argv_counter++] = text;
			text = strtok(NULL, " ");
		}
		argv[argv_counter] = NULL;
		execvp(argv[0], argv);
		ARprint("Error Executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(child_process, &status, WUNTRACED);
		}while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}


