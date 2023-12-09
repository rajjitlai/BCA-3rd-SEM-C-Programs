// Program to implement Diagonal Matrix in one-dimensional array

#include <stdio.h>
int main()
{
	int a[10], n, i, j, an[10][10], count = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements of the array: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("The array is: ");
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		printf(" ");
	}
	// logic for implementing
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				an[i][j] = a[count];
				count++;
			}
			else
				an[i][j] = 0;
		}
	}
	printf("\nThe array in the diagonal matrix is: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", an[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*
Output:

Enter the number of elements: 5
Enter the elements of the array: 1 2 3 4 5
The array is: 1 2 3 4 5 
The array in the diagonal matrix is: 
1	0	0	0	0	
0	2	0	0	0	
0	0	3	0	0	
0	0	0	4	0	
0	0	0	0	5	

*/
