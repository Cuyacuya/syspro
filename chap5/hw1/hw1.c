#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

void print_lines(char lines[][MAX_LINE_LENGTH], int num_lines, char *input) {
    if (strcmp(input, "*") == 0) {
        
        for (int i = 0; i < num_lines; i++) {
            printf("%s", lines[i]);
        }
    } else {
        
        char *token = strtok(input, ",");
        while (token != NULL) {
            if (strchr(token, '-') != NULL) {
                
                int start, end;
                sscanf(token, "%d-%d", &start, &end);
                for (int i = start - 1; i < end && i < num_lines; i++) {
                    printf("%s", lines[i]);
                }
            } else {
                
                int line_num = atoi(token) - 1;
                if (line_num >= 0 && line_num < num_lines) {
                    printf("%s", lines[line_num]);
                }
            }
            token = strtok(NULL, ",");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int num_lines = 0;

    while (fgets(lines[num_lines], MAX_LINE_LENGTH, file) && num_lines < MAX_LINES) {
        num_lines++;
    }
    fclose(file);

    printf("File read success\n");
    printf("Total Line: %d\n", num_lines);
    printf("You can choose 1 and %d\n", num_lines);

    char input[MAX_LINE_LENGTH];
    printf("Pls 'Enter' the line to select: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    print_lines(lines, num_lines, input);

    return 0;
}

