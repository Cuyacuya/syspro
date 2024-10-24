#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
   int fd, chooseid;
   char c;
   struct student record;
   if (argc < 2) {
      fprintf(stderr, "How to use : %s file\n", argv[0]);
      exit(1);
   }
   
   if ((fd = open(argv[1], O_RDWR)) == -1) {
      perror(argv[1]);
      exit(2);
   }

   do {
      printf("--Goods update--\n");
	  printf("(n):sell one goods ] ");
      if (scanf("%d", &chooseid) == 1) {
         lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
         if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.stock == 0)) {
            printf("'%s'(%d) has been sold..\n", record.name, record.id);
			
			printf("%-2s %-20s %-10s %-4s %-3s\n", "id", "name", "category", "expired date", "stock");
				lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
     			write(fd, (char *) &record, sizeof(record) );
   			}



			for(int i=0;i<6;i++) {	
				lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);

				printf("%-2s %-20s %-10s %-4s %-3s\n", &record.id, record.name, record.category, &record.expireddate, &record.stock);
			}
			printf("Enter New Score: ");
            scanf("%d", &record.score);
            lseek(fd, (long) -sizeof(record), SEEK_CUR);
            write(fd, (char *) &record, sizeof(record));
         } else printf("Record %d Null\n", id);
      } else printf("Insert Error\n");
      printf("Continue?(Y/N)");
      scanf(" %c",&c);
   } while (c == 'Y');
   
   close(fd);
   exit(0);
}


