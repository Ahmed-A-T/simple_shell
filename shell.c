#include "shell.h"

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
            executeCommand(command);
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
