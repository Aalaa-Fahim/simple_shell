#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
/* #include <sys/type.h> */
#include <fcntl.h>

void printAR(const char *input);
void input(char *u_input, size_t buf);
void exec(char *u_input);
void prompt();

#endif
