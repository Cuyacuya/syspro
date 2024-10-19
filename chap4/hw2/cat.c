#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_file_with_line_numbers(FILE *fp);
void print_file(FILE *fp);

int main(int argc, char *argv[]) {
    int print_line_numbers = 0;
    int start_index = 1;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-n] file1 [file2 ...]\n", argv[0]);
        return 1;
    }

	if (strcmp(argv[1], "-n") == 0) {
        print_line_numbers = 1;
        start_index = 2;
	}

    for (int i = start_index; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file %s\n", argv[i]);
            return 2;
        }

        if (print_line_numbers) {
            print_file_with_line_numbers(fp);
        } else {
            print_file(fp);
        }

        fclose(fp);
    }

    return 0;
}

void print_file_with_line_numbers(FILE *fp) {
    char line[1024];  
	int line_number = 1;

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%6d  %s", line_number++, line);
    }
}

void print_file(FILE *fp) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
}
