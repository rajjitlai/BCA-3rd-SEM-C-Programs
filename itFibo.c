#include <stdio.h>

int fibonacci(int n) {
    int first = 0, second = 1, next, i;

    for (i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    return next;
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    fibonacci(n);

    return 0;
}
