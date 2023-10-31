// Program to implement Linked Queue usig dynamic memory allocation

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void enqueueLink(struct node **front, struct node **rear, int val) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;

	if ((*front == NULL) && (*rear == NULL)) {
		*front = *rear = newNode;
	} else {
		(*rear)->next = newNode;
		*rear = newNode;
	}
}

void dequeueLink(struct node** front, struct node** rear) {
	if ((*front == NULL) && (*rear == NULL)) {
		printf("\nQueue is empty");
	} else {
		struct node* temp = *front;
		printf("The deleted item is %d", (*front)->data);
		*front = (*front)->next;
		free(temp);
	}
}

void peekQLink(struct node** front, struct node** rear) {
	if ((*front == NULL) && (*rear == NULL)) {
		printf("\nQueue is empty");
	} else {
		printf("\nThe first item is %d", (*front)->data);
	}
}

void displayLink(struct node* front, struct node* rear) {
	struct node* temp = front;
	if (front == NULL) {
		printf("\nQueue is empty");
	} else {
		printf("\nThe liked queue is: \n");
		while (temp != NULL) {
			printf(" %d | ", temp->data);
			temp = temp->next;
		}
	}
}

int main() {
	struct node* front = NULL;
	struct node* rear = NULL;
	int value, n;
	printf("Enter the size of the list: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the data: ");
		scanf("%d", &value);
		enqueueLink(&front, &rear, value);
	}
	int choice;
	do {
		printf("\n\nEnter an option for the following: \n");
		printf("1. Enqueue more elements\n");
		printf("2. Dequeue the list\n3. Peek the list\n4. Display the list\n5. Exit\nYour option: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter the data to enqueue: ");
				scanf("%d", &value);
				enqueueLink(&front, &rear, value);
				break;
			case 2:
				dequeueLink(&front, &rear);
				break;
			case 3:
				peekQLink(&front, &rear);
				break;
			case 4:
				displayLink(front, rear);
				break;
			case 5:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Invalid option. Please choose a valid option.\n");
		}
	} while (choice != 5);
	return 0;
}

// Output
/*
Enter the size of the list: 3
Enter the data: 21
Enter the data: 34
Enter the data: 56


Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 4

The liked queue is:
 21 |  34 |  56 |

Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 2
The deleted item is 21

Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 3

The first item is 34

Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 1
Enter the data to enqueue: 90


Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 4

The liked queue is:
 34 |  56 |  90 |

Enter an option for the following:
1. Enqueue more elements
2. Dequeue the list
3. Peek the list
4. Display the list
5. Exit
Your option: 5
Exiting the program.
*/
