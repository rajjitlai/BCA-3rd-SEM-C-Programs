// Program to illustrate double link list - reverse
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insBeg(struct node **head, int n) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insEnd(struct node **head, int n) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printValue(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
}

void printrevValue(struct node *head) {
    printf("\nThe linked list in reversed form: ");
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n;
    struct node *head = NULL;
    printf("Enter data: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        insBeg(&head, n);
    }
    printf("\nThe linked list is: ");
    printValue(head);
    printrevValue(head);
    return 0;
}
