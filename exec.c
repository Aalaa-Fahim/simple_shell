#include "main.h"

/**
 * exec - function to execute input.
 * @inputStr: input string.
 */
void exec(char *u_input)
{
	char *argv[1024];
	int argc = 0, status;
	char *text;
	pid_t child_process = fork();

    if (child_process == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_process == 0)
    {
        text = strtok((char *)u_input, " ");
        while (text != NULL)
        {
            argv[argc++] = text;
            text = strtok(NULL, " ");
        }
        argv[argc] = NULL;
        if (execvp(argv[0], argv) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do {
            waitpid(child_process, &status, WUNTRACED);
        }while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
