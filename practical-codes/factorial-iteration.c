#include <stdio.h>

int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int number, fact;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    fact = factorial(number);
    printf("Factorial of %d is: %llu\n", number, fact);

    return 0;
}
