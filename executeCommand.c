#include "shell.h"

/**
 * executeCommand - Executes the given command in a child process.
 * @command: The command to be executed.
 */
void executeCommand(char *command)
{
    /* Allocate memory for the args array */
    char **args = malloc(2 * sizeof(char *));
    if (args == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    /* Set the command and NULL as arguments */
    args[0] = command;
    args[1] = NULL;

    /* Execute the command */
    execve(command, args, environ);

    /* If execve fails, print an error message */
    perror("Error executing command");
    free(args);
    exit(EXIT_FAILURE);
}
