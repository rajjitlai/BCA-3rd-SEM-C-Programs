// Program to implement double-linked-list with insertion at beginning, at end, at any position and and also delete from the beginning
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insBeg(struct node** head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

void insEnd(struct node** head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insPos(struct node** head, int val, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (pos <= 1) {
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = newNode;
        }

        *head = newNode;
    } else {
        struct node* temp = *head;
        int currentPos = 1;
        while (temp != NULL && currentPos < pos - 1) {
            temp = temp->next;
            currentPos++;
        }

        if (temp == NULL) {
            printf("Position exceeds the length of the list. Inserting at the end.\n");
            insEnd(head, val);
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
}

void deleteBeg(struct node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

void displayElement(struct node* head) {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int val, pos, choice;
    struct node* head = NULL;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at a specific position\n4. Delete from the beginning\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &val);
                insBeg(&head, val);
                break;

            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &val);
                insEnd(&head, val);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insPos(&head, val, pos);
                break;

            case 4:
                deleteBeg(&head);
                break;

            case 5:
                displayElement(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}