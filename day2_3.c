/*Given an unsorted array of size n, WAP using pointer and DMA to find and display the
number of elements between two elements a and b (both inclusive).
Sample Input:
Enter the value of n: 6
Enter the elements: 1 2 2 7 5 4 Enter the value of a: 2
Enter the value of b: 5
Sample Output:
Number of elements: 3
The numbers are: 2, 2, 5*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    int i, ai = -1, bi = -1, count = 0;
    printf("My Roll Number is 25155278\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    // find first index where value == a, and first index where value == b
    int *p = arr;
    for (i = 0; i < n; i++, p++) {
        if (ai == -1 && *p == a) ai = i;
        if (bi == -1 && *p == b) bi = i;
    }

    if (ai == -1 || bi == -1) {
        printf("Either a or b not found in the array.\n");
        free(arr);
        return 1;
    }

    int start = ai, end = bi;
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    int lo = (a < b) ? a : b;
    int hi = (a > b) ? a : b;

    // allocate worst-case space for qualifying elements
    int *result = (int *)malloc((end - start + 1) * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return 1;
    }

    p = arr + start;
    for (i = start; i <= end; i++, p++) {
        if (*p >= lo && *p <= hi) {
            *(result + count) = *p;
            count++;
        }
    }

    printf("Number of elements: %d\n", count);
    printf("The numbers are: ");
    for (i = 0; i < count; i++) {
        printf("%d", *(result + i));
        if (i != count - 1) printf(", ");
    }
    printf("\n");

    free(arr);
    free(result);
    return 0;
}