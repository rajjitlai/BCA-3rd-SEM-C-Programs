// Program for creation of link list and display the number of nodes created
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, val;
    struct node *head = NULL;
    int nodeCount = 0;

    printf("Program for creation of a linked list and displaying the number of nodes created\n");

    while (1) {
        printf("Enter a value (or -1 to stop): ");
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        nodeCount++;
    }

    printf("The linked list has %d nodes.\n", nodeCount);
    printf("The elements in the linked list are: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    return 0;
}
