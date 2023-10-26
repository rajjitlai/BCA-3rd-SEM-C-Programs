// Program to implment insertion and deletion in Queue
#include<stdio.h>
#include<stdlib.h>
void enqueue(int arr[], int rear, int n) {
	if(rear == n - 1)
		printf("Queue full");
	else {
		rear++;
		printf("Enter the array data: ");
		scanf("%d", &arr[rear]);
	}
}

void dequeue(int arr[], int front, int rear) {
	if(front == rear)
		printf("Queue empty");
	else {
		front++;
		printf("The deleted item is %d", arr[front]);
	}
}

void display(int arr[], int front, int rear) {
	if (front == rear)
		printf("Queue is empty\n");
	else {
		printf("Queue elements: ");
		for (int i = front + 1; i <= rear; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
	int a[50], num, rear = -1, front = -1, choice;
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	if (num > 50)
		printf("Queue size cannot exceed 50.\n");
	else {
		do {
			printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			switch (choice) {
				case 1:
					enqueue(a, rear, num);
					break;
				case 2:
					dequeue(a, front, rear);
					break;
				case 3:
					display(a, front, rear);
					break;
				case 4:
					printf("Exiting...\n");
					exit(0);
				default:
					printf("Invalid choice. Try again.\n");
			}
		} while (choice != 4);
	}
	return 0;
}
// there are some error that needs to be fixed