#include <stdio.h>

void swap(int *x, int *y);

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main()
{
    int x = 5, y = 10;
    printf("Before swapping, the value of x is %d\nand the value of y is %d", x, y);
    swap(&x, &y);
    printf("\nAfter swapping, the value of x is %d\nand the value of y is %d", x, y);
    return 0;
}
