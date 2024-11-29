#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void printStackAndClear(struct node **top) {
    printf("Print stack\n");
    while (*top != NULL) {
        struct node *temp = *top;
        printf("%d\n", temp->data);
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    struct node *stack = NULL;
    char input[256];

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        char *endptr;
        double num = strtod(input, &endptr);

        if (*endptr == '\0') {
            if (num > 0 && num == (int)num) {
                push(&stack, (int)num);
            } else if (num > 0) {
                push(&stack, (int)num);
                printStackAndClear(&stack);
                break;
            } else {
                printStackAndClear(&stack);
                break;
            }
        } else {
            printStackAndClear(&stack);
            break;
        }
    }

    return 0;
}

