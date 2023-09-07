#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10] = {10, 22, 12, 20, 55, 82, 100, 21, 50, 52};
    int num;
    int pos = -1;

    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter an element to be searched: ");
    scanf("%d", &num);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == num)
        {
            pos = i + 1;
            break;
        }
    }
    if (pos !=  -1)
    {
        printf("%d found at position %d\n", num, pos);
    }
    else
    {
        printf("%d not found in the array\n", num);
    }

    return 0;
}

// Output:
// Original array: 10 22 12 20 55 8 2 100 21 50 52 
// Enter an element to be searched: 12
// 12 found at position 3