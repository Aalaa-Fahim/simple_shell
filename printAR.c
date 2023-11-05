#include "main.h"
/**
 * printAR - function to print into standered output.
 * @input: message to print.
 * Return: void
 */
void printAR(const char *input)
{
	int len = strlen(input);
	weite(STDOUT_FILENO, input, len);
}
