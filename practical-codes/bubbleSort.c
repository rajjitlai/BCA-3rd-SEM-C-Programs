#include <stdio.h>
int main()
{
    int arr[10];
    int i, j, temp, n, flag;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    printf("Sorted list is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Output:
// Enter the number of elements: 5
// Enter the elements: 44 21 90 10 67
// Sorted list is:
// 10 21 44 67 90