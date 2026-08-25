// Swap the nth and last elements of an linked list in C
#include <stdio.h>
#include <stdlib.h>
void swap_nth_last();
void create_list();
void traverse_list();
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
int main() {
    create_list();
    printf("Original list:\n");
    traverse_list();
    swap_nth_last();
    printf("List after swapping nth and last nodes:\n");
    traverse_list();
    return 0;
}
void swap_nth_last() {
    int n;
    printf("Enter the position of the node to swap with the last node: ");
    scanf("%d", &n);
    if (head == NULL || head->next == NULL) {
        printf("List is too short to swap.\n");
        return;
    }
    struct Node* nth_node = head;
    struct Node* last_node = head;
    int count = 1;
    while (last_node->next != NULL) {
        last_node = last_node->next;
        count++;
    }
    if (n > count || n < 1) {
        printf("Position out of bounds.\n");
        return;
    }
    for (int i = 1; i < n; i++) {
        nth_node = nth_node->next;
    }
    if (nth_node == last_node) {
        return;
    }
    int temp = nth_node->data;
    nth_node->data = last_node->data;
    last_node->data = temp;
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
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}