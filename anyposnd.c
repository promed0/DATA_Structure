#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void del_pos(struct node **head, int position){
    struct node *current = *head;
    struct node *previous = *head;
    if (*head == NULL)
    {
        printf("List already full.");
    }
    else if (position ==1 )
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while (position != 1)
        {
            previous= current;
            current = previous ->link;
            position --;
        }
        previous->link = current->link;
        free(current);
        current = NULL;   
    }
};
int main(){
    struct node *head;
    int position = 2;
    del_pos(&head, position);
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}