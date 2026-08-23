/*Linked List creation and traversal*/
#include <stdio.h>
#include <stdlib.h>
void create_linked_list();
void traverse_linked_list();
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
int main() {
    int choice = 100;
    while (choice != 0) {
        printf("\n\n1. Create linked list\n2. Traverse linked list\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_linked_list(); break;
            case 2: traverse_linked_list(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
void create_linked_list() {
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    printf("Linked list created with %d nodes.\n", n);
}
void traverse_linked_list() {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}