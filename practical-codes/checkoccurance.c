 // Program to find the number of occurrence of an element X inside an array A[N]
#include <stdio.h>
int main()
{
	int A[10], i, N, X;
	int c = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &N);
	printf("Enter the elements of the array: ");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("Enter the element to be checked: ");
	scanf("%d", &X);
	for (i = 0; i < N; i++)
	{
		if (A[i] == X)
		{
			c++;
		}
	}
	if (c != 0)
		printf("The occurrence of %d is %d", X, c);
	else
		printf("There is no occurrence of %d in the given array", X);
	return 0;
}

/*
Output:
Enter the number of elements: 5
Enter the elements of the array: 12 32 11 12 12
Enter the element to be checked: 12
The occurrence of 12 is 3

*/
