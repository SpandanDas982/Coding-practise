/*WAP using structure and DMA to store n employees’ data such as employee name,
gender, designation, department, basic pay. Calculate the gross pay of each employee as
follows: Gross pay=basic pay + HR + DA, HR=25% of basic, DA=50% of basic.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("My Roll Number is 25155278\n");
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee {
        char name[50];
        char gender[10];
        char designation[50];
        char department[50];
        float basicPay;
    };
    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Gender: ");
        scanf("%s", emp[i].gender);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Department: ");
        scanf("%s", emp[i].department);
        printf("Basic Pay: ");
        scanf("%f", &emp[i].basicPay);
    }
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        float hr = 0.25 * emp[i].basicPay;
        float da = 0.50 * emp[i].basicPay;
        float grossPay = emp[i].basicPay + hr + da;
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Gender: %s\n", emp[i].gender);
        printf("Designation: %s\n", emp[i].designation);
        printf("Department: %s\n", emp[i].department);
        printf("Basic Pay: %.2f\n", emp[i].basicPay);
        printf("Gross Pay: %.2f\n", grossPay);
    }
    free(emp);
    return 0;
}