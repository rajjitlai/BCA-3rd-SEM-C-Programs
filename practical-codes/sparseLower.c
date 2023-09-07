// #include <stdio.h>

// int main()
// {
//     int n;
//     printf("Enter the size: ");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             printf("* ");
//         }
//         printf("\n");
//     }

//     return 0;
// }

// Output
// Enter the size: 5
// *
// * *
// * * *
// * * * *
// * * * * *
/*---------------------------------------------------------*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", num + j);
        }
        printf("\n");
        num++;
    }

    return 0;
}

// Output
// Enter the number of rows: 5
// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9
