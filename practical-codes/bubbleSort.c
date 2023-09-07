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
        for (j = 0; j < n - 1 - i; i++)
        {
            flag = 0;
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
            }
            if (flag == 1)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted list is: \n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}