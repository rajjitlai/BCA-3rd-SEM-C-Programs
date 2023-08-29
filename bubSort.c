#include <stdio.h>

int main()
{
    int arr[10], temp;
    //  ctr = 0;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // ctr++;
            // printf("Step %d: ", ctr);
            // for (int k = 0; k < n; k++)
            //     printf("%d ", arr[k]);
            // printf("\n");
        }
    }
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
