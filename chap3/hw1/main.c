#include <stdio.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE][MAXLINE];

int main() {
    int len;
    int max;
    int Num = 0;
    max = 0;

    for(int i = 0; i < 5; i++) {
		gets(line);
        len = strlen(line);
        
        if(len > max) {
            max = len;
        }
        
        copy(line, longest[Num]);
        Num++;
    }

    for(int i = max; i > 0; i--) {
        for(int j = 0; j < Num; j++) {
            if(strlen(longest[j]) == i) {
                printf("%s\n", longest[j]);
            }
        }
    }

    return 0;
}
