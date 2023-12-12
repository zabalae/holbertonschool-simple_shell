#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void execute_command(char *cmd, char *self);
char *getInput(void);
void print_environment(void);
void execute_command(char *args[]);

#endif
