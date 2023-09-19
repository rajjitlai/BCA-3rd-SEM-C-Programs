#include <stdio.h>

int main()
{
    int arr[10] = {24, 73, 21, 19, 50, 33};
    int i, j, save;

    for (i = 1; i < 6; i++)
    {
        save = arr[i];
        for (j = i - 1; j >= 0 && save < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = save;
    }

    printf("The sorted array is: \n");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Output
// The sorted array is:
// 19 21 24 33 50 73