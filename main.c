#include "main.h"

void prompt()
{
    printf("simple_shell$ ");
}

int main()
{
    size_t buf = 0;
    char *u_input = NULL;

    while (1)
    {
        prompt();
        input(&u_input, &buf);
        exec(u_input);
    }
    free(u_input);
    return 0;
}
