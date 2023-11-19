#include <stdio.h>

// Function to find the factorial of a number using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to find the factors of a number using recursion
void factors(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    factors(n, i + 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial of %d is %d\n", num, factorial(num));
    printf("Factors of %d are: ", num);
    factors(num, 1);

    return 0;
}
