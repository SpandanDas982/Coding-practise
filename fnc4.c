//reverse single linked list using recursion.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int data;
    struct Node* next;
};
void create_linked_list(struct Node** head);
void reverse_linked_list(struct Node** head);
void traverse_linked_list(struct Node* head);
int main() {
    srand(time(NULL));
    struct Node* head = NULL;
    create_linked_list(&head);
    printf("Original linked list:\n");
    traverse_linked_list(head);
    reverse_linked_list(&head);
    printf("\nReversed linked list:\n");
    traverse_linked_list(head);
    return 0;
}   
void create_linked_list(struct Node** head) {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = rand() % 100 + 1; 
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
            temp = *head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
}
void reverse_linked_list(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct Node* rest = (*head)->next;
    reverse_linked_list(&rest);
    (*head)->next->next = *head;
    (*head)->next = NULL;
    *head = rest;
}
void traverse_linked_list(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* sir's logic for reverse linked list
LL* reverse_list(LL* head)
  {LL* prev,*curr,*nextptr;
    prev=NULL;
    curr=head;
   while(curr!=NULL)
  {
    nextptr=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextptr;
  }
    head=prev;
   return head;
}*/