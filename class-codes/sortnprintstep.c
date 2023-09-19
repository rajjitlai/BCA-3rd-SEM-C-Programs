/*C program to sort an array of n integers into ascending order using the 
easiest method and it should  be written in a module and should be 
called when required only; also print the number of exchanges and comparison*/

#include <stdio.h>
void insertionSort(int arr[], int n, int *exchanges, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            (*exchanges)++;
            j--;
        }
        arr[j + 1] = key;
        printf("Step %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int arr[n];
    int exchanges = 0;
    int comparisons = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n, &exchanges, &comparisons);
    printf("The sorted list is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of exchanges: %d\n", exchanges);
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
