/*Arrays (following operations to be performed)
o Insert random, Delete, Linear search, Traversal, smallest and largest element, reverse the array element, sorting and
searching an element in a dynamic array.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insert_element();
void delete_element();
void linear_search();
void traversal();
void smallest_largest();
void reverse_array();
void sorting();
void searching();\
int main() {
    srand(time(NULL));
    int choice = 100;
    printf("My Roll no:- 25155278\n");
    while (choice != 0) {
        printf("\n\n1. Insert element \n2. Delete element\n3. Linear search\n4. Traversal\n5. Smallest and largest element\n6. Reverse array\n7. Sorting\n8. Searching  \n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_element(); break;
            case 2: delete_element(); break;
            case 3: linear_search(); break;
            case 4: traversal(); break;
            case 5: smallest_largest(); break;
            case 6: reverse_array(); break;
            case 7: sorting(); break;  
            case 8: searching(); break;  
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
void insert_element() {
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; 
    }
    printf("Elements inserted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}
void delete_element() {
    int n;
    printf("Enter the number of elements to delete: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; 
    }
    printf("Elements before deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int index;
    printf("Enter the index of the element to delete (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Elements after deletion: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid index!\n");
    }
    free(arr);
}