#include "main.h"
/**
 * printEnv - function to print the environ variable.
 *
 * Return: void function.
 */
void printEnv(void)
{
	char **env = environ;
	int i;

	for (i = 0 ;env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
