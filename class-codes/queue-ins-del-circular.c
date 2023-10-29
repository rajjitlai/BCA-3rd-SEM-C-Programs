// Program to implment enqueue, dequeue, display and searching in circular queue
#include <stdio.h>

int rear = -1;
int front = -1;

// Function to enqueue an element in a circular queue
void enqueueCir(int arr[], int n) {
	if ((rear == -1) && (front == -1)) {
		rear = front = 0;
		printf("Enter the data: ");
		scanf("%d", &arr[rear]);
	} else if (front == ((rear + 1) % n)) {
		printf("Queue is full\n");
	} else {
		rear = (rear + 1) % n;
		printf("Enter the data: ");
		scanf("%d", &arr[rear]);
	}
}

// Function to dequeue an element from a circular queue
void dequeueCir(int arr[], int n) {
	if (front == -1 && rear == -1) {
		printf("The queue is empty\n");
	} else if (front == rear) {
		printf("The deleted item is %d\n", arr[front]);
		front = rear = -1;
	} else {
		printf("The deleted item is %d\n", arr[front]);
		front = (front + 1) % n;
	}
}

// Function to display the elements in the circular queue
void displayQueue(int arr[], int n) {
	if (front == -1 && rear == -1) {
		printf("Queue is empty\n");
	} else {
		int i = front;
		printf("Queue elements: ");
		while (1) {
			printf("%d | ", arr[i]);
			if (i == rear) break;
			i = (i + 1) % n;
		}
		printf("\n");
	}
}

// Function to search for an item in the circular queue
void searchQueueCir(int arr[], int n, int item) {
	if (front == -1 && rear == -1) {
		printf("The queue is empty\n");
	} else {
		int i = front, c = 1, flag = 0;
		while (1) {
			if (item == arr[i]) {
				flag = 1;
				break;
			}
			if (i == rear) break;
			i = (i + 1) % n;
			c++;
		}
		if (flag == 1) {
			printf("%d found at position %d\n", item, c);
		} else {
			printf("%d not found\n", item);
		}
	}
}

int main() {
	int a[20], num;
	int choice, item;

	printf("Enter the number of elements: ");
	scanf("%d", &num);

	do {
		printf("\nMenu:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display Queue\n");
		printf("4. Search in Queue\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				enqueueCir(a, num);
				break;
			case 2:
				dequeueCir(a, num);
				break;
			case 3:
				displayQueue(a, num);
				break;
			case 4:
				printf("Enter the item to search: ");
				scanf("%d", &item);
				searchQueueCir(a, num, item);
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice. Try again.\n");
		}
	} while (choice != 5);

	return 0;
}
