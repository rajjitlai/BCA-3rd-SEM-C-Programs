/* Program to create a link list and give options to insert data at the beginning, at any position or at the end - NORMAL*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    *head = newNode;
}

void insAtPos(struct node **head, int pos) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    if (*head == NULL || pos == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        temp = *head;
        for (int i = 1; i < pos-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position. Element not inserted.\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAtEnd(struct node **head) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printValue(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int op, pos;
    struct node *head = NULL;
    printf("Enter the type of insertion you want: \n1. At the beginning\n2. At any position\n3. At the end \n");
    scanf("%d", &op);
    while (1) {
        switch (op) {
            case 1:
                insertAtBeginning(&head);
                break;
            case 2:
                insAtPos(&head, pos);
                break;
            case 3:
                insertAtEnd(&head);
                break;
            default:
                printf("You have entered an invalid option...\n");
                exit(0);
        }
        printf("The list is:\n");
        printValue(head);
        printf("Enter the type of insertion you want (or any other value to exit): ");
        scanf("%d", &op);
    }
    return 0;
}

// Output:
// Enter the type of insertion you want:
// 1. At the beginning
// 2. At any position
// 3. At the end
// 1
// Enter the value to be inserted: 23
// The list is:
// 23
// Enter the type of insertion you want (or any other value to exit): 1
// Enter the value to be inserted: 34
// The list is:
// 34
// 23
// Enter the type of insertion you want (or any other value to exit): 3
// Enter the value to be inserted: 45
// The list is:
// 34
// 23
// 45
// Enter the type of insertion you want (or any other value to exit): 2
// Enter the value to be inserted: 32
// Enter the position you want to insert: 3
// The list is:
// 34
// 23
// 32
// 45
// Enter the type of insertion you want (or any other value to exit): 4
// You have entered an invalid option...