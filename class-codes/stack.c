// Program to implement STACK, including 3 modules for push, pop and display - 8 marks
#include<stdio.h>

int top = -1;

void push(int arr[], int n) {
	if (top == n - 1)
		printf("Stack Overflow");
	else {
		top++;
		printf("Enter data: ");
		scanf("%d", &arr[top]);
	}
}

void pop(int arr[]) {
	if (top ==  -1)
		printf("Stack Underflow");
	else {
		printf("\nThe deleted item is %d", arr[top]);
		top--;
	}
}

void display(int arr[]) {
	if(top == -1)
		printf("Stack Underflow");
	else {
		printf("\n----\n");
		for(int i = top; i >= 0; i--)
			printf("%d\n----\n", arr[i]);
	}
}

int main() {
	int arr[20], n;
	printf("Enter the size of the list: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		push(arr, n);
	}
	printf("\nThe stack data before pop is: ");
	display(arr);	
	pop(arr);
	printf("\nThe stack data after pop is: ");
	display(arr);
	return 0;
}

// Output: 
/*
Enter the size of the list: 5
Enter data: 12
Enter data: 23
Enter data: 34
Enter data: 45
Enter data: 56

The stack data before pop is:
----
56
----
45
----
34
----
23
----
12
----

The deleted item is 56
The stack data after pop is:
----
45
----
34
----
23
----
12
----
*/

// peek function
//void peek(int arr[]){
//	if(top == -1)
//		printf("Stack underflow");
//	else{
//		printf("The top data is %d", arr[top]);
//	}
//}