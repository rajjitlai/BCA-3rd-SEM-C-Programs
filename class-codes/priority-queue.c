// Program to implement priority queue
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data, priority;
	struct node *next;
};

void enqueue(struct node **front) {
	struct 	node *newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newNode -> data);
	printf("Enter the priority of the number: ");
	scanf("%d", &newNode -> priority);

	newNode -> next = NULL;
	if(*front==NULL || newNode->priority <= (*front)-> priority) {
		newNode -> next = *front;
		*front = newNode;
	} else {
		struct node *temp = *front;
		while (temp -> next!=NULL && temp ->next->priority <= newNode-> priority)
			temp = temp -> next;
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}
}

void dequeue(struct node **front, struct node **rear) {
	if((*front == NULL)&& (*rear==NULL)) {
		printf("Queue is empty");
	} else {
		struct node *temp = *front;
		printf("\nThe deleted item is %d", (*front)->data);
		*front=(*front)->next;
		free(temp);
	}
}

void display(struct node *front, struct node *rear) {
	struct node *temp = front;
	if((front==NULL) && (rear == NULL))
		printf("Queue is empty");
	else {
		printf("\nThe list is : \n| ");
		while(temp != NULL) {
			printf("%d - %d | ", temp -> data, temp -> priority);
			temp = temp -> next;
		}
	}
}

int main() {
	int n;
	printf("Enter the size of the items: ");
	scanf("%d", &n);
	struct node *front = NULL, *rear = NULL;
	for(int i =1; i<= n; i++) {
		enqueue(&front);
	}
	printf("\nBefore the deletion");
	display(front, rear);
	dequeue(&front, &rear);
	printf("\nAfter the deletion");
	display(front, rear);
	return 0;
}

// Output
/*
Enter the size of the items: 5
Enter the data: 34
Enter the priority of the number: 2
Enter the data: 56
Enter the priority of the number: 1
Enter the data: 44
Enter the priority of the number: 5
Enter the data: 23
Enter the priority of the number: 3
Enter the data: 60
Enter the priority of the number: 4

Before the deletion
The list is :
| 56 - 1 | 34 - 2 | 23 - 3 | 60 - 4 | 44 - 5 |
The deleted item is 56
After the deletion
The list is :
| 34 - 2 | 23 - 3 | 60 - 4 | 44 - 5 |
*/