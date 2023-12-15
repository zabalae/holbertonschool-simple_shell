#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>

#define ARGS_SIZE 259

void execute(char *cmd, char *self, char *envp[]);
char *getInput(void);
void print_enviroment(char *envp[]);
char *validCommand(char *cmd);
int spaceChecker(char *cmd);

#endif
