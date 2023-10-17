#include <stdio.h>

int main() {
    int inputs[10];
    int results[10] = {0};
    int isRepetition = 0; 
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &inputs[i]);
    }

    for (int i = 0; i < 10; i++) {
        results[i] = inputs[i] * i;
        for (int j = 0; j < i; j++) {
            if (results[i] == results[j]) {
                isRepetition = 1;
                break;
            }
        }
    }

    printf("Results:\n");
    for (int i = 0; i < 10; i++) {
        printf("Input[%d] * %d = %d\n", i, i, results[i]);
    }

    if (isRepetition) {
        printf("There are repetitions in the results.\n");
    } else {
        printf("There are no repetitions in the results.\n");
    }

    return 0;
}

// Output:
// Enter 10 integers:
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
// Results:
// Input[0] * 0 = 0
// Input[1] * 1 = 2
// Input[2] * 2 = 6
// Input[3] * 3 = 12
// Input[4] * 4 = 20
// Input[5] * 5 = 30
// Input[6] * 6 = 42
// Input[7] * 7 = 56
// Input[8] * 8 = 72
// Input[9] * 9 = 90
// There are no repetitions in the results.
