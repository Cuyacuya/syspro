#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    char command[256], *args[16];
    while (1) {
        printf("pls input cmd: ");
        if (fgets(command, 256, stdin) == NULL) {
            printf("\nExit\n");
            break;
        }
        command[strcspn(command, "\n")] = 0;

        int i = 0;
        char *token = strtok(command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell.\n");
            break;
        }

        printf("[%d] Parent process start\n", getpid());

        int background = 0;
        if (args[i - 1] && strcmp(args[i - 1], "&") == 0) {
            background = 1;
            args[--i] = NULL;
        }

        pid_t pid = fork();
        if (pid == 0) {
            printf("[%d] Child process start\n", getpid());
            for (int j = 0; j < i; ++j) {
                if (strcmp(args[j], ">") == 0) {
                    int fd = open(args[j + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    args[j] = NULL;
                } else if (strcmp(args[j], "<") == 0) {
                    int fd = open(args[j + 1], O_RDONLY);
                    dup2(fd, STDIN_FILENO);
                    close(fd);
                    args[j] = NULL;
                }
            }
            execvp(args[0], args);
            perror("Execution failed");
            printf("[%d] Child process end\n", getpid());
            exit(1);
        } else {
            if (!background) {
                wait(NULL);
            }
            printf("[%d] Parent process end\n", getpid());
        }
    }
    return 0;
}

