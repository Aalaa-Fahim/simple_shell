#include "main.h"

/**
 * printAR - function to print into standard output.
 * @input: message to print.
 */
void printAR(const char *input)
{
	int len = strlen(input);
	write(STDOUT_FILENO, input, len);
}
