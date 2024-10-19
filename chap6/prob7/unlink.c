#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[ ])
{
   if (unlink(argv[1]) == -1) {
      exit(1);
   }
   exit(0);
}

