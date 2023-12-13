#include "shell.h"

extern char **environ;  /* Declaration of the environment variable */
/**
 * displayPrompt - Displays the shell prompt.
 */
void displayPrompt(void)
{
    printf("myshell> ");
}

/**
 * main - The main function for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;

    while (1)
    {
        /* Display prompt and read user input */
        displayPrompt();
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            /* Handle end of file condition (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove newline character from the input */
        command[strcspn(command, "\n")] = '\0';

        /* Fork a child process */
        pid = fork();

        if (pid < 0)
        {
            /* Forking error */
            perror("Error forking");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Child process */

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
        else
        {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
            {
                /* If child process exited normally */
                printf("Command executed with status %d\n", WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                /* If child process terminated by a signal */
                printf("Command terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}
