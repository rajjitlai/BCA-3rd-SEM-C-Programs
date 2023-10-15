#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct node **head, int val) {
    struct node *newNode = createNode(val);
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

int search(struct node *head, int val) {
    struct node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element %d found at position %d.\n", val, position);
            return 1;  // Element found
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", val);
    return 0;  // Element not found
}

void display(struct node *head) {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int val;
    struct node *head = NULL;

    printf("Enter values for the list (enter -1 to finish):\n");
    
    while (1) {
        printf("Enter a value: ");
        scanf("%d", &val);
        
        if (val == -1) {
            break;  // Exit the loop when -1 is entered
        }
        
        insertAtEnd(&head, val);
    }

    display(head);

    printf("Enter a value to search in the list: ");
    scanf("%d", &val);

    search(head, val);

    // Free memory
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
