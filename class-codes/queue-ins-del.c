// Program to implment insertion and deletion in Queue
#include<stdio.h>
#include<stdlib.h>
int enqueue(int arr[], int rear, int n) {
	if(rear == n - 1)
		printf("Queue is full");
	else {
		rear++;
		printf("Enter the array data: ");
		scanf("%d", &arr[rear]);
	}
	return rear;
}

int dequeue(int arr[], int front, int rear) {
	if(front == rear)
		printf("Queue empty");
	else {
		front++;
		printf("The deleted item is %d", arr[front]);
	}
	return front;
}

void disqueue(int arr[], int front, int rear) {
	if (front == rear)
		printf("Queue is empty\n");
	else {
		printf("\nQueue elements: ");
		for (int i = front + 1; i <= rear; i++) {
			printf("%d |", arr[i]);
		}
		printf("\n");
	}
}

void peekq(int arr[], int front, int rear) {
	if(front == rear)
		printf("Queue empty");
	else {
		front++;
		printf("The deleted item is %d", arr[front]);
	}
}

int main() {
	int a[20], num, rear = -1, front = -1;
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	if (num > 20)
		printf("Queue size cannot exceed 20.\n");
	else {
		rear = enqueue(a, rear, num);
		rear = enqueue(a, rear, num);
		rear = enqueue(a, rear, num);
		disqueue(a, front, rear);
		front = dequeue(a, front, rear);
		disqueue(a, front, rear);
		peekq(a, front, rear);
	}
	return 0;
}

// Output:
/*
Enter the number of elements: 5
Enter the array data: 21
Enter the array data: 24
Enter the array data: 56

Queue elements: 21 |24 |56 |
The deleted item is 21
Queue elements: 24 |56 |
The deleted item is 24
*/