#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int pid, pid2, child, status;
   printf("[%d] parental process start\n", getpid());
   pid = fork();
   if (pid == 0) {
      printf("[%d] child process start\n", getpid());
	  sleep(1);
	  printf("[%d] child process end\n", getpid());
      exit(1);
   }
   pid2 = fork();
   if(pid2 == 0){
	   printf("[%d] child2 process start\n", getpid());
	   sleep(2);
	   printf("[%d] child2 process end\n", getpid());
	   exit(2);
   }

   child = waitpid(pid, &status, 0);
   printf("[%d] child process %d end \n", getpid(), child);
   printf("\tend code  %d\n", status>>8);
}
