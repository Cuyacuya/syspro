#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*tail) {
        (*tail)->next = newNode;
    }
    *tail = newNode;

    if (*head == NULL) {
        *head = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return data;
}

void printQueueAndClear(struct node **head, struct node **tail) {
    printf("Print queue\n");
    while (*head != NULL) {
        printf("%d\n", delete(head, tail));
    }
}

int main() {
    struct node *head = NULL, *tail = NULL;
    char input[256];
    int value;

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "%d", &value) == 1 && value > 0) {
            addq(&head, &tail, value);
        } else {
            printQueueAndClear(&head, &tail);
            break;
        }
    }

    return 0;
}

