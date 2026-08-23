#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void create_dll();
void traverse_forward();
void traverse_backward();
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
void check_if_empty();
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
int main() {
    srand(time(NULL));
    int choice = 100;
    printf("My Roll Number is 25155278\n");
    printf("You are about to create a double linked list. Please follow the menu options to perform operations on the list.\n");
    printf("Please note that the list will be created with random values between 1 and 100.\n");
    printf("Now please proceed with the Linked list creation.\n");
    create_dll();
        printf("\n\n1. Traverse forward \n2. Traverse backward\n3. Check if list is empty\n4. Insert at beginning\n5. Insert at end\n6. Insert at position\n7. Delete at beginning\n8. Delete at end\n9. Delete at position\n10. Delete by key\n11. Count nodes\n12. Search element  \n0. Exit\n");
        while (choice != 0) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: traverse_forward(); break;
            case 2: traverse_backward(); break;
            case 3: check_if_empty(); break;
            case 4: insert_at_beginning(); break;
            case 5: insert_at_end(); break;
            case 6: insert_at_position(); break;
            case 7: delete_at_beginning(); break;
            case 8: delete_at_end(); break;
            case 9: delete_at_position(); break;
            case 10:delete_by_key(); break;
            case 11:count_nodes(); break;
            case 12:search_element(); break;  
            case 0: exit(0);
            default:printf("Invalid choice!\n");
        }
    }
    return 0;
}
void create_dll() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = rand() % 100 + 1; 
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            temp = temp->next;
        }
    }
    traverse_forward();
}
void traverse_forward() {
    if (head==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        struct Node* temp = head;
        printf("The list in forward order is:");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void traverse_backward() {
    if (head==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        struct Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("The list in backward order is:");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
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
    new_node->prev = NULL;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
    printf("Node inserted at the beginning with value: %d\n", new_node->data);
    traverse_forward();
}
void insert_at_end() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("Node inserted at the end with value: %d\n", new_node->data);
    traverse_forward();
}
void insert_at_position() {
    int position;
    printf("Enter the position to insert (0 for beginning): ");
    scanf("%d", &position);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = rand() % 100 + 1; 
    if (position == 0) {
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        printf("Node inserted at position %d with value: %d\n", position, new_node->data);
        traverse_forward();
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
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    printf("Node inserted at position %d with value: %d\n", position, new_node->data);
    traverse_forward();
}
void delete_at_beginning() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Node deleted from the beginning with value: %d\n", temp->data);
    free(temp);
    traverse_forward();
}
void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL; 
    }
    printf("Node deleted from the end with value: %d\n", temp->data);
    free(temp);
    traverse_forward(); 
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
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Node deleted from position %d with value: %d\n", position, temp->data);
        free(temp);
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Node deleted from position %d with value: %d\n", position, temp->data);
    free(temp);
    traverse_forward();
}
void delete_by_key() {
    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; 
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Node with key %d deleted from the list.\n", key);
    free(temp);
    traverse_forward();
}
void count_nodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The number of nodes in the list is: %d\n", count);
}
void search_element() {
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Key %d not found in the list.\n", key);
}