// Program to reverse a linked list - a single linked list
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

void printElementReverse(struct node *head) {
	if (head == NULL) {
		return;
	}
	printElementReverse(head->next);
	printf("%d | ", head->data);
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
	
	printf("\nReversed List: ");
	printElementReverse(head);
	printf("\n");

	return 0;
}

// Output:
/*
Enter the number of elements you want to insert: 5
Enter the value for element 1: 34
Enter the value for element 2: 56
Enter the value for element 3: 89
Enter the value for element 4: 22
Enter the value for element 5: 10
The elements in the list are: 34 | 56 | 89 | 22 | 10 |
Reversed List: 10 | 22 | 89 | 56 | 34 |
*/