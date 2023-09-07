#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("  ");
        }
        for (int j = i; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

// Output
// Enter the size: 5
// * * * * * 
//   * * * * 
//     * * * 
//       * * 
//         * 