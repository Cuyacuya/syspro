 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
 
 int main(int argc, char* argv[]) {
    int fd;
    int line = 0;
	int index = 0;
    char input[10];
    char savedText[10][100];
    char buf;
 
    //Open File
    if((fd = open("text.txt", O_RDONLY)) == -1) {
        perror("Fail to Open text.txt");
        exit(1);
    }

    //cp test.txt => savedText
    while (read(fd, &buf, 1) > 0) {
        if(buf == '\n') {
            savedText[line][index] = '\0';
            line++;
            index = 0;
        }
        else savedText[line][index++] = buf;
    }

    close(fd);
    
    printf("File read success\n");
    printf("You can choose 1 ~ 4 Line\n");
    printf("Pls 'Enter' ther line to select : ");
  
    scanf("%s", input);
	
    if(input[0] == '*') {
        for(int i=0;i<line;i++) printf("%s\n", savedText[i]);
    }
    
    else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end); //Data Parse
        for (int i = start - 1; i < end; i++) {
            printf("%s\n", savedText[i]);
        }
    }
    
    else {
        int n;
        sscanf(input, "%d", &n);
		printf("%s\n", savedText[n-1]);
    }
}

