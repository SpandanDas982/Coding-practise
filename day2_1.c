//WAP using pointer, DMA to search an element in an array of n numbers.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, key, found = 0,c;
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
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            c=i;
            break;
        }
    }
    if (found) {
        printf("Element %d found in the array at index %d.\n", key, c);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    free(arr);
    return 0;
}