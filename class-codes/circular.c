// Program to implement Circular linkd list
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

void insBeg(struct node **head) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	printf("Enter data (beginning): ");
	scanf("%d", &newNode -> data);
	if(*head == NULL) {
		newNode -> next = newNode;
		*head = newNode;
	} else {
		temp = *head;
		while(temp -> next != *head)
			temp = temp -> next;
		temp -> next = newNode;
		newNode -> next = *head;
		*head = newNode;
	}
}

void insEnd(struct node **head) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	printf("Enter data (end): ");
	scanf("%d", &newNode -> data);
	if(*head == NULL) {
		newNode -> next = newNode;
	} else {
		temp = *head;
		while(temp ->next != *head)
			temp = temp -> next;
		temp -> next = newNode;
		newNode -> next = *head;
	}
}

void insPos(struct node **head) {
	int pos;
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	printf("Enter the data: ");
	scanf("%d", &newNode -> data);
	printf("Enter the position you want to insert: ");
	scanf("%d", &pos);
	if(*head == NULL || pos == 0) {
		newNode -> next = *head;
		*head = newNode;
	} else {
		temp = *head;
		for (int i = 1; i < pos-1 && temp != NULL; i++) {
			temp = temp->next;
		}
		if (temp == NULL) {
			printf("Invalid position. Element cannot be inserted.\n");
		} else {
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}

// deletions will be added later

void printValue(struct node *head) {
    struct node *temp = head;
    if (head != NULL) {
        do {
            printf("%d | ", temp->data);
            temp = temp->next;
        } while (temp != head);
    } else {
        printf("List is empty.");
	}
}

    
int main() {
	struct node *head = NULL;
	int choice;

	do {
		printf("Circular Linked List Operations:\n");
		printf("1. Insert at the beginning\n");
		printf("2. Insert at the end\n");
		printf("3. Insert at a specific position\n");
		printf("4. Print the list\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				insBeg(&head);
				break;
			case 2:
				insEnd(&head);
				break;
			case 3:
				insPos(&head);
				break;
			case 4:
				printf("Circular Linked List: ");
				if (head != NULL) {
					printValue(head);
				} else {
					printf("List is empty.");
				}
				printf("\n");
				break;
			case 5:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Invalid choice. Please enter a valid option.\n");
		}
	} while (choice != 5);

	return 0;
}

