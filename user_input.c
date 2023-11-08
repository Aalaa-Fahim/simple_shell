#include "main.h"

/**
 * input - Check the user input.
 * @u_input: the received user input.
 */
void input(char **u_input, size_t *buf)
{
    if (getline(u_input, buf, stdin) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        } else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }
}
