#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *del_last(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->next != NULL) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));

    // Assign values
    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = NULL;

    head = node1;

    // Delete the last node
    head = del_last(head);

    // Print the remaining list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}
