#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat"

int main(int argc, char *argv[])
{
   int fd, id;
   int check;
   char c; 
   struct student record;
   
   if (argc < 2) {
      fprintf(stderr, "How to use : %s file\n", argv[0]);
      exit(1);
   }
   
   if ((fd = open(argv[1], O_RDONLY)) == -1) {
      perror(argv[1]);
      exit(2);
   }
      printf("0: list of all goods, 1: list of available goods ) ");


      if (scanf("%d", &check) == 0) {
		   printf("%-2s\t %-15s\t %-8s\t %-12s\t %-5s\n", "id","name","category","date","stock");
           
		   for(int i=0;i<6;i++){
			lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) 
               printf("%-2d\t %-15s\t %-8s\t %-12d\t %-5d\n", record.id, record.name, record.category, record.expireddate, record.stock);
            else printf("Record %d is  Null\n", id);
      	 }
	 // else if(scanf("%d", &check) == 1) {
	 //     printf("%-2s\t %-15s\t %-8s\t %-12s\t %-5s\n", "id","name","category","date","stock");
     //     	for(int i=0;i<6;i++){
     //       	lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
     //       	if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)){
	//				if((record.expireddate > 2022) && record.stock > 0)
     //                printf("%-2d\t %-15s\t %-8s\t %-12d\t %-5d\n", record.id, record.name, record.category, record.expireddate, record.stock);
      //    		else printf("Record %d is  Null\n", id);
		//		}	
	  //		}
		}

  
   close(fd);
   exit(0);
}


