#include <stdio.h>

int binarySearch(int arr[], int size, int num, char op)
{
    int left = 0, right = size - 1;
    int pos = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
        {
            if (op == 'f')
                return mid + 1;
            else if (op == 'b')
                return size - mid;
        }

        if (arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return pos;
}

int main()
{
    int arr[10] = {10, 12, 20, 21, 22, 50, 52, 55, 82, 100};
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
    case 'f':
    case 'b':
        pos = binarySearch(arr, 10, num, op);
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

/*
Original array: 10 12 20 21 22 50 52 55 82 100
Enter an element to be searched: 21
Enter the mode for searching - f for forward or b for backward: f
21 found at position 4

Original array: 10 12 20 21 22 50 52 55 82 100
Enter an element to be searched: 20
Enter the mode for searching - f for forward or b for backward: b
20 found at position 8

Original array: 10 12 20 21 22 50 52 55 82 100
Enter an element to be searched: 57
Enter the mode for searching - f for forward or b for backward: b
57 not found in the array
*/