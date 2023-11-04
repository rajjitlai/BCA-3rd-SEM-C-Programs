// Program to implement Rear Enueue in Double Ended Queue
#include<stdio.h>
int rear = -1;
int front = -1;

void enqueueRear(int arr[], int n) {
	if((front == -1) && (rear == -1)) {
		front = rear = 0;
		printf("Enter the data: ");
		scanf("%d",&arr[rear]);
	} else if((front==0) && ( rear==n-1)||front==rear+1)
		printf("Queue is full");
	else if(rear==n-1) {
		rear=0;
		printf("Enter the data: ");
		scanf("%d",&arr[rear]);
	} else {
		rear++;
		printf("Enter the data: ");
		scanf("%d",&arr[rear]);
	}
}

void enqueueFront(int arr[], int n) {
	if((front == -1) && (rear == -1)) {
		front = rear = 0;
		printf("Enter the data: ");
		scanf("%d",&arr[front]);
	} else if((front==0) && ( rear==n-1)||front==rear+1)
		printf("Queue is full");
	else if(front == 0) {
		front=n-1;
		printf("Enter the data: ");
		scanf("%d",&arr[front]);
	} else {
		front--;
		printf("Enter the data: ");
		scanf("%d",&arr[front]);
	}
}

void displayList(int arr[], int n) {
	if((front == -1) && (rear == -1)) {
		printf("Queue is empty");
	} else {
		int i = front;
		printf("\nThe list is: ");
		while(i != rear) {
			printf(" %d |", arr[i]);
			i = (i + 1)%n;
		}
		printf("%d |", arr[rear]);
	}
}

void dequeueFront(int arr[], int n)	{
	if((front == -1) && (rear == -1)) {
		printf("Queue is empty");
	} else if(front==rear) {
		printf("\nThe deleted item is: %d", arr[front]);
	} else if(front==0) {
		printf("\nThe deleted item is: %d", arr[front]);
		front = n - 1;
	} else {
		printf("\nThe deleted item is: %d", arr[front]);
		front++;
	}
}

int main(){
	int arr[50];
	int n;
	printf("Enter the number of data: ");
	scanf("%d", &n);
	if( n > 50){
		printf("The numbers of items cannot be greater than 50");
	}else{
		enqueueRear(arr, n);
		enqueueRear(arr, n);
		enqueueRear(arr, n);
		
		enqueueFront(arr, n);
		enqueueFront(arr, n);
	}
	printf("Before deletion: ");
	displayList(arr, n);
	dequeueFront(arr, n);
	printf("\nAfter deletion: ");
	displayList(arr, n);
	
	return 0;
}