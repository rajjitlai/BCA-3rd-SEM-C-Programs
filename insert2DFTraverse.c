#include <stdio.h>
#include <conio.h>

int main()
{
    float arr[3][3];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    printf("After traversing the array: \n");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the elements of the array: 1.2
// 3.4
// 2.2
// 1
// 7.6
// 4.5
// 3.3
// 8.2
// 1.1
// After traversing the array:
// 1.20 3.40 2.20
// 1.00 7.60 4.50
// 3.30 8.20 1.10