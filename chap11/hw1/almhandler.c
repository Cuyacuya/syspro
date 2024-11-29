#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler(int signo);

struct sigaction newact;

int main() {
    newact.sa_handler = alarmHandler;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;

    alarm(5);

    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}
