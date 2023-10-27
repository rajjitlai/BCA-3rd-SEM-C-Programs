// Program to implment enqueue in circular queue
#include <stdio.h>

int enqueue(int arr[], int rear, int front, int n) {
    if ((rear + 1) % n == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % n;
        printf("Enter the data: ");
        scanf("%d", &arr[rear]);
    }
    return rear;
}

void displayQueue(int arr[], int front, int rear, int n) {
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        do {
            printf("%d | ", arr[i]);
            i = (i + 1) % n;
        } while (i != (rear + 1) % n);
        printf("\n");
    }
}

int main() {
    int a[20], num, rear = -1, front = -1;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    while (rear < num - 1) {
        rear = enqueue(a, rear, front, num);
    }
    displayQueue(a, front, rear, num);
    return 0;
}
