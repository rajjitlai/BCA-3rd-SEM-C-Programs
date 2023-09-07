#include <stdio.h>

int main()
{
    int arr[10] = {10, 22, 12, 20, 55, 82, 100, 21, 50, 52};
    int num;
    int pos = -1;
    char op;

    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter an element to be searched: ");
    scanf("%d", &num);
    printf("Enter the mode for searching - f for forward or b for backward: ");
    scanf(" %c", &op);
    switch (op)
    {
    case 'b':
        for (int i = 9; i >= 0; i--)
        {
            if (arr[i] == num)
            {
                pos = 10 - i;
                break;
            }
        }
        break;
    case 'f':
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == num)
            {
                pos = i + 1;
                break;
            }
        }
        break;
    default:
        printf("Invalid option\n");
        return 1;
    }
    if (pos != -1)
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
// f
// Original array: 10 22 12 20 55 82 100 21 50 52
// Enter an element to be searched: 22
// Enter the mode for searching - f for forward or b for backward: f
// 22 found at position 2

// b
// Original array: 10 22 12 20 55 82 100 21 50 52 
// Enter an element to be searched: 100
// Enter the mode for searching - f for forward or b for backward: b
// 100 found at position 4