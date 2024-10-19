#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>

// Function to print file information based on user options
void print_file_info(const char *filename, int show_inode, int use_quotes) {
    struct stat file_stat;
    
    // Get file information
    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        return;
    }
    
    // Print i-node number
    if (show_inode) {
        printf("%ld ", file_stat.st_ino);
    }

    // Print permission information
    printf("%c", (S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
    printf("%c", (file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    printf("%c", (file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("%c", (file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    printf("%c", (file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("%c", (file_stat.st_mode & S_IROTH) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c", (file_stat.st_mode & S_IXOTH) ? 'x' : '-');

    // Print number of hard links
    printf(" %ld", file_stat.st_nlink);

    // Print owner information
    struct passwd *owner = getpwuid(file_stat.st_uid);
    struct group *group = getgrgid(file_stat.st_gid);
    printf(" %s %s", owner->pw_name, group->gr_name);

    // Print file size
    printf(" %ld", file_stat.st_size);

    // Print last modification time
    char time_buf[80];
    struct tm *timeinfo = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", timeinfo);
    printf(" %s", time_buf);

    // Print file name
    if (use_quotes) {
        printf(" \"%s\"\n", filename);
    } else {
        printf(" %s\n", filename);
    }
}

int main(int argc, char *argv[]) {
    int show_inode = 0; // Flag to determine if i-node number should be shown
    int use_quotes = 0; // Flag to determine if file name should be enclosed in quotes

    // Process command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            show_inode = 1; // Enable showing i-node number
        } else if (strcmp(argv[i], "-Q") == 0) {
            use_quotes = 1; // Enable enclosing file name in quotes
        } else if (strcmp(argv[i], "-p") == 0) {
            // The -p option does not require additional information
            continue;
        } else {
            printf("Unknown option: %s\n", argv[i]); // Print error for unknown option
            return 1;
        }
    }

    // Set default file name
    const char *filename = "test.txt";

    // Print file information
    print_file_info(filename, show_inode, use_quotes);

    return 0; // Exit the program
}

