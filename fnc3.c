/*Linked List creation,traversal, insert at beginning and insert at end, reverse the list, count nodes,sum of nodes*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create_linked_list();
void traverse_linked_list();
void insert_at_beginning();
void insert_at_end();
void reverse_linked_list();
void count_nodes();
void sum_of_nodes();
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
int main() {
    srand(time(NULL));
    int choice = 100;
    while (choice != 0) {
        printf("\n\n1. Create linked list \n2. Traverse linked list\n3. Insert at beginning\n4. Insert at end\n5. Reverse linked list\n6. Count nodes\n7. Sum of nodes  \n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_linked_list(); break;
            case 2: traverse_linked_list(); break;
            case 3: insert_at_beginning(); break;
            case 4: insert_at_end(); break;
            case 5: reverse_linked_list(); break;
            case 6: count_nodes(); break;
            case 7: sum_of_nodes(); break;  
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
void create_linked_list() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = rand() % 100 + 1; 
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
void insert_at_beginning() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
    new_node->next = head;
    head = new_node;
    printf("Node inserted at the beginning with value: %d\n", new_node->data);
}
void insert_at_end() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
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
    printf("Node inserted at the end with value: %d\n", new_node->data);
}
void reverse_linked_list() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list reversed.\n");
}
void count_nodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes in the linked list: %d\n", count);
}
void sum_of_nodes() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all nodes in the linked list: %d\n", sum);
}
