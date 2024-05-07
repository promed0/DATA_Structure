#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *del_first(struct node *head)
{
    if (head == NULL) 
    {
        printf("The list is empty");
    }
    else{
        struct node *temp = head;
        head = head->link;
        free(temp);

    }
    return head;
};
int main(){
   struct node *head = NULL;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));

    // Assign values
    node1->data = 10;
    node1->link = node2;

    node2->data = 20;
    node2->link = node3;

    node3->data = 30;
    node3->link = NULL;

    head = node1;

    // Delete the last node
    head = del_first(head);

    // Print the remaining list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
return 0;
}
