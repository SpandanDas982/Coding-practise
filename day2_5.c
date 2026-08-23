#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, y;
    int i, last_x = -1, last_y = -1, min_dist = -1;
    printf("My Roll Number is 25155278\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    int *p = arr;
    for (i = 0; i < n; i++, p++) {
        if (*p == x) {
            last_x = i;
            if (last_y != -1) {
                int dist = last_x - last_y;
                if (dist < 0) dist = -dist;
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
        } else if (*p == y) {
            last_y = i;
            if (last_x != -1) {
                int dist = last_y - last_x;
                if (dist < 0) dist = -dist;
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
        }
    }

    printf("Minimum distance between %d and %d is %d.\n", x, y, min_dist);

    free(arr);
    return 0;
}