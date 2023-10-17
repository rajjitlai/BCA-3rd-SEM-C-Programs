#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int multiples[10]; 
    int count = 0;

    for (int i = 1; i <= 100; i++) { 
        int multiple = num * i;
        if (multiple % 7 == 0) {
            multiples[count] = multiple;
            count++;
        }
    }

    if (count == 0) {
        printf("No multiples of %d are divisible by 7.\n", num);
    } else {
        printf("Multiples of %d that are divisible by 7:\n", num);
        for (int i = 0; i < count; i++) {
            printf("%d\n", multiples[i]);
        }
    }

    return 0;
}

// Output:
// Enter a number: 5
// No multiples of 5 are divisible by 7.
