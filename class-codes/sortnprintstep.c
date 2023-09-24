/* C program to sort an array of n integers into ascending order using the 
easiest method and it should  be written in a module and should be 
called when required only; also print the number of exchanges and comparison*/
#include <stdio.h>
void bubSort(int arr[50], int n) {
    int ex = 0;
    int com = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            com++;
            if (arr[j] > arr[j + 1]) {
                ex++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of exchanges: %d\n", ex);
    printf("Number of comparisons: %d\n", com);
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubSort(arr, n);
    return 0;
}
