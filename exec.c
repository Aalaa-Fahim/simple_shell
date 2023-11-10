#include "main.h"
/**
 * exec - function to execute input.
 * @inputStr: input string.
 */
void exec(char *u_input)
{
	pid_t child_process;
	char **argv;
	int argc = 0, status;
	char *text, *tmp_cmd = NULL, *last_cmd = NULL;
	
	text = strtok(u_input, " ");
	argv = malloc(sizeof(char *) * 1024);
	while (text != NULL)
	{
		argv[argc] = text;
		text = strtok(NULL, " ");
		argc++;
	}
	argv[argc] = NULL;
	child_process = fork();
	if (child_process == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		tmp_cmd = argv[0];
		last_cmd = search(tmp_cmd);
		execve(last_cmd, argv, NULL);
		perror("No such file or directory\n");
		exit(EXIT_FAILURE);
	}
    else
    {
        do {
            waitpid(child_process, &status, WUNTRACED);
        }while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
