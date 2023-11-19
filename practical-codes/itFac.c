#include <stdio.h>

// Function to find the factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to find the factors of a number
void factors(int num) {
    printf("Factors of %d: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Find and print the factorial of the number
    int fact = factorial(num);
    printf("Factorial of %d: %d\n", num, fact);

    // Find and print the factors of the number
    factors(num);

    return 0;
}
