// Program to create a link list and display the elements in the list
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertElement(struct node **head, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
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

void printElement(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
}

int main() {
	int n, i, val;
	struct node *head = NULL;
	printf("Enter the number of elements you want to insert: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter the value for element %d: ", i + 1);
		scanf("%d", &val);
		insertElement(&head, val);
	}

	printf("The elements in the list are: ");
	printElement(head);

	return 0;
}