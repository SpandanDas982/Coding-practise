//application of functions
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int *arr = NULL;
int n=0;
void array_declare();
void array_display();
void array_LargestSmallest();
void array_Descending_sort();
int main(){
    srand(time(NULL));
    int choice=100;
    while(choice!=0){
        printf("\n\n1. Declare array\n2. Display array\n3. Largest and Smallest\n4. Sort in descending order\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: array_declare(); break;
            case 2: array_display(); break;
            case 3: array_LargestSmallest(); break;
            case 4: array_Descending_sort(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }return 0;
}
void array_declare(){// declaration function
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i] = rand()%100+1;
    }
    printf("Array declared and initialized with random values.\n");
}
void array_display(){
    if(arr == NULL){
        printf("Array not declared yet!\n");
        return;
    }
    printf("Array elements: ");
    for(int i=0;i<n-1;i++){
        printf("%d-> ",arr[i]);
    }
    printf("%d\n",arr[n-1]);
}
void array_LargestSmallest(){
    if(arr == NULL){
        printf("Array not declared yet!\n");
        return;
    }
    int largest = arr[0];
    int smallest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > largest) largest = arr[i];
        if(arr[i] < smallest) smallest = arr[i];
    }
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
}
void array_Descending_sort() {
    if(arr == NULL){
        printf("Array not declared yet!\n");
        return;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Array sorted in descending order.\n");
}

/*For random values in a particular range we use the formula: min + rand() % (max - min + 1) */