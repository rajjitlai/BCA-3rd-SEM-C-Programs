// Program for creation of link list and display the number of nodes created
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int val) {
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayCount(struct node *head) {
    int count = 0;
    struct node *temp = head;
    printf("\nThe linked list is: ");
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nThe number of nodes created is %d\n", count);
}

int main() {
    int val;
    struct node *head = NULL;
    printf("Enter values for the list (enter -1 to finish):\n");
    while (1) {
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        insert(&head, val);
    }
    displayCount(head);
    return 0;
}

