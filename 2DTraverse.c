#include <stdio.h>
#include <conio.h>
int main()
{
    int arr[3][3];
    printf("Enter the elements for the 2D array: ");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("After traversing the 2D array: \n");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the elements for the 2D array: 1 2 3 4 5 6 7 8 9 
// After traversing the 2D array:
// 1 2 3
// 4 5 6
// 7 8 9