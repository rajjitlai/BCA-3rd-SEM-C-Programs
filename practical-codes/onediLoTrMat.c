// Program to implement Lower Triangular Matrix in one-dimensional array

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int inputArray[n * (n + 1) / 2]; // One-dimensional array
    int matrix[n][n];                // Two-dimensional array

    printf("Enter %d elements of the one-dimensional array:\n", n * (n + 1) / 2);
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        scanf("%d", &inputArray[i]);
    }
    int inputArrayIndex = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                matrix[i][j] = inputArray[inputArrayIndex];
                inputArrayIndex++;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }

    printf("The lower triangular matrix is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Output:

Enter the size of the square matrix: 3
Enter 6 elements of the one-dimensional array:
1 2 3 4 5 6
The lower triangular matrix is:
1	0	0	
2	3	0	
4	5	6

*/
