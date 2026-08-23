//WAP using DMA to find out the smallest and largest element stored in an array of n integers.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("My Roll Number is 25155278\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);
    free(arr);
    return 0;
}