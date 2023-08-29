#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the diagonal sparse matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("Enter the value for position (%d, %d): ", i, j);
                scanf("%d", &matrix[i][j]);
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
    printf("Diagonal Sparse Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
