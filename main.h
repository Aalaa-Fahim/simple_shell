#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>

extern char **environ;
void printEnv(void);
void printAR(const char *input);
void input(char *u_input, size_t buf);
void exec(char *u_input);
void prompt(void);
void non_interactive_mode(char *u_input);
char *search(char *tmp_cmd);

#endif
