#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat() error");
        return 1;
    }

    struct utimbuf newTimes;
    newTimes.actime = fileStat.st_atime;
	newTimes.modtime = fileStat.st_mtime;

    if (utime(argv[2], &newTimes) < 0) {
        perror("utime() error");
        return 1;
    }

    printf("Updated %s timestamps with those of %s\n", argv[2], argv[1]);
    return 0;
}

