// Program to implment enqueue in circular queue
#include <stdio.h>
int rear = -1;
int front = -1;

void enqueueCir(int arr[], int n){
	if((rear == -1) && (front == -1))
	{
		rear = front = 0;
		printf("Enter the data: ");
		scanf("%d", &arr[rear]);
	}
	else if (front == ((rear + 1) % n)){
		printf("Queue is full");
	}
	else{
		rear = (rear + 1) % n;
		printf("Enter the data: ");
		scanf("%d", &arr[rear]);
	}
}

void displayQueue(int arr[], int n) {
    if((rear == -1) && (front == -1)){
    	printf("Queue is empty");
	}
	else{
		int i = front;
		printf("\nQueue elements");
		while(i != rear){
			printf(" %d | ", arr[i]);
			i = (i + 1) % n;
		}
		printf(" %d", arr[rear]);
	}
}

int main() {
    int a[20], num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    enqueueCir(a, num);
    enqueueCir(a, num);
    enqueueCir(a, num);
    displayQueue(a, num);
    return 0;
}

// Output:
/*
Enter the number of elements: 5
Enter the data: 1
Enter the data: 2
Enter the data: 3

Queue elements 1 |  2 |  3
*/