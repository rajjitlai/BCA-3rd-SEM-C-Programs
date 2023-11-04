// Program to implement Rear Enueue in Double Ended Queue
#include<stdio.h>
int rear = -1;
int front = -1;

void enueueRear(int arr[], int n){
    if((front == -1) && (rear == -1)){
        front = rear = 0;
        printf("Enter the data");
        scanf("%d",&arr[rear]);
    }else if((front==0) && ( rear==n-1)||front==rear+1))
        printf("Queue is full");
    else if(rear==n-1){
        rear=0;
        printf("enter the data:")
        scanf("%d",&arr[rear]);
    }else{
        rear++;
        printf("enter the data:")
        scanf("%d",&arr[rear]);
    }
}
