#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int left, int right, int num)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
            return mid + 1;

        if (arr[mid] > num)
            return binarySearch(arr, left, mid - 1, num);

        return binarySearch(arr, mid + 1, right, num);
    }

    return -1;
}

int main()
{
    int arr[10] = {10, 12, 20, 21, 22, 50, 52, 55, 82, 100};
    int num;
    int pos = -1;

    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter an element to be searched: ");
    scanf("%d", &num);

    pos = binarySearch(arr, 0, 9, num);

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
Output: 
Original array: 10 12 20 21 22 50 52 55 82 100
Enter an element to be searched: 58
58 not found in the array

Original array: 10 12 20 21 22 50 52 55 82 100
Enter an element to be searched: 55
55 found at position 8
*/