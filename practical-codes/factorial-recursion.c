#include <stdio.h>
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int number, fact;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    fact = factorial(number);
    printf("Factorial of %d is: %d\n", number, fact);

    return 0;
}
