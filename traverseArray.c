// Program to traverse the array
#include<stdio.h>
#include<conio.h>

int main(){
    int arr[5];
    printf("Enter the elements for the array: ");
    for(int i=0 ;i<5; i++){
        scanf("%d", &arr[i]);
    }
    printf("After traversing the array: \n");
    for(int i=0; i <5; i++){
        printf("Element at index %d is %d\n", i, arr[i]);
    }
    return 0;
}
// Output:
// Enter the elements for the array: 4 5 6 7 8 9 
// After traversing the array: 
// Element at index 0 is 4
// Element at index 1 is 5
// Element at index 2 is 6
// Element at index 3 is 7
// Element at index 4 is 8