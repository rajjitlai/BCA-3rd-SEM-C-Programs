#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertAtBeginning(struct node **head) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value to be inserted: ");
	scanf("%d", &newNode->data);
	newNode->next = *head;
	*head = newNode;
}

void insertAtEnd(struct node **head) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *temp = *head;
	printf("Enter the value to be inserted: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtPosition(struct node **head, int position) {
	if (position <= 0) {
		printf("Invalid position.\n");
		return;
	}
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value to be inserted: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;

	if (position == 1) {
		newNode->next = *head;
		*head = newNode;
		return;
	}

	struct node *temp = *head;
	int currentPos = 1;
	while (currentPos < position - 1 && temp != NULL) {
		temp = temp->next;
		currentPos++;
	}

	if (temp == NULL) {
		printf("Invalid position. The list has fewer elements.\n");
		free(newNode);
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void printValue(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	int op, position;
	struct node *head = NULL;

	while (1) {
		printf("Choose an option:\n");
		printf("1. Insert at the beginning\n");
		printf("2. Insert at the end\n");
		printf("3. Insert at any position\n");
		printf("4. Exit\n");

		scanf("%d", &op);

		switch (op) {
			case 1:
				insertAtBeginning(&head);
				break;
			case 2:
				insertAtEnd(&head);
				break;
			case 3:
				printf("Enter the position where you want to insert: ");
				scanf("%d", &position);
				insertAtPosition(&head, position);
				break;
			case 4:
				printf("Exiting the program.\n");
				exit(0);
			default:
				printf("Invalid option. Please choose a valid option.\n");
				break;
		}

		printf("Updated Linked List: ");
		printValue(head);
	}

	return 0;
}
