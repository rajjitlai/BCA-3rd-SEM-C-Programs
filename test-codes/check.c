#include <stdio.h>

int main()
{
    int arr[10], i;
    arr[0] = 1;
    arr[1] = 1;
    for (i = 2; i < 10; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("The inserted array is: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    if (arr[i] == 11)
    {
        printf("\n11 is in the array");
    }
    else
    {
        printf("\n11 is not present in the array ");
    }
}