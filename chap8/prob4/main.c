#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

static void exit_handler1(void), exit_handler2(void);

int main(void) {
if (atexit(exit_handler1) != 0)	
  perror("exit_handler1 can't enroll");
if (atexit(exit_handler2) != 0) 	
  perror("exit_handler2 can't enroll");
printf("main end \n");
exit(0);
}

static void exit_handler1(void) {
	printf("first exit process\n");
}

static void exit_handler2(void) {
	printf("second exit process\n");
}
