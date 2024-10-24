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
    if((fd = open("data.txt", O_RDONLY)) == -1) {
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

		for(int i=0;i<2;i++) printf("%s\n", savedText[i]);
}

