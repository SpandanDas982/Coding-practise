// Swap the first and last nodes of an linked list in C
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void swap_first_last();
void create_list();
void traverse_list();
int main() {
    create_list();
    printf("Original list:\n");
    traverse_list();
    swap_first_last();
    printf("List after swapping first and last nodes:\n");
    traverse_list();
    return 0;
}
void swap_first_last() {
    if (head == NULL || head->next == NULL) {
        printf("List is too short to swap.\n");
        return;
    }
    struct Node* first = head;
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    if (first == last) {
        return;
    }
    int temp = first->data;
    first->data = last->data;
    last->data = temp;
}
void create_list() {
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}
void traverse_list() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}