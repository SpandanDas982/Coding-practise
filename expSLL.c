#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void create_linked_list();
void traverse_linked_list();
void check_if_empty();
void insert_at_beginning();
void insert_at_end();
void insert_at_position();
void delete_at_beginning();
void delete_at_end();
void delete_at_position();
void delete_by_key();
void count_nodes();
void search_element();
int main() {
    srand(time(NULL));
    int choice = 100;
     printf("My Roll Number is 25155278\n");
     printf("You are about to create a single linked list. Please follow the menu options to perform operations on the list.\n");
     printf("Please note that the list will be created with random values between 1 and 100.\n");
     printf("Now please proceed with the Linked list creation.\n");
     create_linked_list();  
        printf("\n\n1. Traverse linked list \n2. Check if list is empty\n3. Insert at beginning\n4. Insert at end\n5. Insert at position\n6. Delete at beginning\n7. Delete at end\n8. Delete at position\n9. Delete by key\n10. Count nodes\n11. Search element  \n0. Exit\n");
        while (choice != 0) { 
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: traverse_linked_list(); break;
            case 2: check_if_empty(); break;
            case 3: insert_at_beginning(); break;
            case 4: insert_at_end(); break;
            case 5: insert_at_position(); break;
            case 6: delete_at_beginning(); break;
            case 7: delete_at_end(); break;
            case 8: delete_at_position(); break;
            case 9: delete_by_key(); break;
            case 10: count_nodes(); break;
            case 11: search_element(); break;  
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
    traverse_linked_list(); 
}
void traverse_linked_list() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void check_if_empty() {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }
}
void insert_at_beginning() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
    new_node->next = head;
    head = new_node;
    printf("Node inserted at the beginning with value: %d\n", new_node->data);
    traverse_linked_list(); 
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
    traverse_linked_list();
}
void insert_at_position() {
    int position;
    printf("Enter the position to insert (0 for beginning): ");
    scanf("%d", &position);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
    if (position == 0) {
        new_node->next = head;
        head = new_node;
        printf("Node inserted at position %d with value: %d\n", position, new_node->data);
        traverse_linked_list();
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Node inserted at position %d with value: %d\n", position, new_node->data);
    traverse_linked_list();
}
void delete_at_beginning() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Node deleted from the beginning with value: %d\n", temp->data);
    free(temp);
    traverse_linked_list();
}
void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Node deleted from the end with value: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Node deleted from the end with value: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    traverse_linked_list();
}
void delete_at_position() {
    int position;
    printf("Enter the position to delete (0 for beginning): ");
    scanf("%d", &position);
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        printf("Node deleted from position %d with value: %d\n", position, temp->data);
        free(temp);
        traverse_linked_list();
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    printf("Node deleted from position %d with value: %d\n", position, node_to_delete->data);
    free(node_to_delete);
    traverse_linked_list();
}
void delete_by_key() {
    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        printf("Node with key %d deleted from the list.\n", key);
        free(temp);
        traverse_linked_list();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    printf("Node with key %d deleted from the list.\n", key);
    free(node_to_delete);
    traverse_linked_list();
}
void count_nodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes in the list: %d\n", count);
}
void search_element() {
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}
