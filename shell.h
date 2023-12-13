#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_COMMAND_LENGTH 100

/**
 * displayPrompt - Displays the shell prompt.
 */
void displayPrompt(void);

/**
 * executeCommand - Executes the given command in a child process.
 * @command: The command to be executed.
 */
void executeCommand(char *command);

#endif /* MYSHELL_H */

