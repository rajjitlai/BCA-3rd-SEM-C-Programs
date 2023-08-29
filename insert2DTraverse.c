#include <stdio.h>
#include <conio.h>
int main()
{
    char arr[3][3];
    printf("Enter the elements for the 2D array: ");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }
    printf("After traversing the 2D array: \n");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the elements for the 2D array: character
// After traversing the 2D array:
// c h a
// r a c
// t e r