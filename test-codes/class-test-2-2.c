// Create a doubly linked list and insert at the beginning and search for an item
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

void displayElement(struct node* head) {
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void searchElement(struct node** head, int val) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node* temp = *head;
    int found = 0;
    int pos = 1;
    while (temp != NULL) {
        if (val == temp->data) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (found) {
        printf("Element %d found at position %d.\n", val, pos);
    } else {
        printf("Element %d not found.\n", val);
    }
}

int main() {
    struct node* head = NULL;
    int choice, val;

    do {
        printf("1. Insert at the beginning\n2. Search for an item\n3. Display the list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &val);
                insBeg(&head, val);
                break;
            case 2:
                printf("Enter the item to search: ");
                scanf("%d", &val);
                searchElement(&head, val);
                break;
            case 3:
                displayElement(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
