// Program to reverse the elements of a stack using additional stack

#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push(int arr[], int n)
{
    if (top == n - 1)
        printf("Stack overflow!");

    else
    {
        top++;
        printf("Enter data: ");
        scanf("%d", &arr[top]);
    }
}

void display(int arr[])
{
    if (top == -1)
        printf("Stack underflow");
    else
    {
        printf("The elements of the stack are: ");
        printf("\n---\n");
        for (int i = top; i >= 0; i--)
            printf(" %d\n---\n", arr[i]);
    }
}

void reverse(int arr[], int revA[])
{
    if (top == -1)
        printf("Stack underflow");
    else
    {
        int j = 0;
        for (int i = top; i >= 0; i--)
        {
            revA[j] = arr[i];
            j++;
        }
    }
}

int main()
{
    int n, i, arr[100], revA[100];
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        push(arr, n);
    display(arr);
    reverse(arr, revA);
    printf("\nAfter reversing stack: ");
    display(revA);
}

// Output:
/*
Enter the size of stack: 5
Enter data: 1
Enter data: 2
Enter data: 3
Enter data: 4
Enter data: 5
The elements of the stack are: 
---
 5
---
 4
---
 3
---
 2
---
 1
---

After reversing stack: The elements of the stack are: 
---
 1
---
 2
---
 3
---
 4
---
 5
---
*/