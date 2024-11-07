#include <stdio.h>
#include <unistd.h>

int main()
{    
   printf("My process num :  [%d] \n", getpid());
   printf("My Parents process num¸ : [%d] \n", getppid());
}
