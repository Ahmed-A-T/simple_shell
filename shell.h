#ifndef SHELL_H
#define SHELL_H
#define MAX_COMMAND_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

void displayPrompt(void);

#endif
