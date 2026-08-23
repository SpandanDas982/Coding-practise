/*Let A be nXn square matrix array. WAP by using appropriate user defined functions for
the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the leading diagonal elements.*/
#include <stdio.h>
void count_nonzero(int n, int matrix[n][n]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Number of nonzero elements: %d\n", count);
}
void sum_above_leading_diagonal(int n, int matrix[n][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum of elements above the leading diagonal: %d\n", sum);
}
void display_below_minor_diagonal(int n, int matrix[n][n]) {
    printf("Elements below the minor diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j >= n) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}
void product_of_leading_diagonal(int n, int matrix[n][n]) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= matrix[i][i];
    }
    printf("Product of leading diagonal elements: %d\n", product);
}
int main() {
    int n;
    printf("My Roll Number is 25155278\n");
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    count_nonzero(n, matrix);
    sum_above_leading_diagonal(n, matrix);
    display_below_minor_diagonal(n, matrix);
    product_of_leading_diagonal(n, matrix);
    return 0;
}