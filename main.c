#include "main.h"

void prompt()
{
	printf("($) ");
}

int main()
{
	char u_input[1024];

	while (1)
    	{
		prompt();
        	input(u_input, sizeof(u_input));
        	exec(u_input);
	}
	return 0;
}
