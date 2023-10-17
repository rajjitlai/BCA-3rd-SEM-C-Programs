#include <stdio.h>
int factorial(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int arr[10];
    printf("Enter 10 elements into the array:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    if (arr[5] % 2 == 0) {
        int fact = factorial(arr[5]);
        printf("Factorial of the element at index 5 is: %d\n", fact);
    } else {
        arr[5] *= 11;
        printf("Element at index 5 multiplied by 11: %d\n", arr[5]);
    }

    return 0;
}

// Output:
// Enter 10 elements into the array:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// Element at index 5 multiplied by 11: 55

// Output 2:
// Enter 10 elements into the array:
// 1
// 2
// 3
// 4
// 5
// 10
// 7
// 8
// 9
// 10
// Factorial of the element at index 5 is: 3628800
