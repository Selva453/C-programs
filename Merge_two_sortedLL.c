/******************************************************************************

                           Merge two sorted LL using recursion.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

void insert (struct node **head_ref, int data){
    struct node *new_node = (struct node *)malloc(sizeof (struct node));
    new_node->data = data;
    new_node->next = *(head_ref);
    *(head_ref) = new_node;
}
struct node * sorted_merge(struct node *a, struct node *b){
    struct node * result = NULL;
    
    if (a == NULL){
        return b;
    } else if (b == NULL){
        return a;
    }
    if (a->data <= b->data){
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}


void printLL (struct node *head_ref){
    struct node *temp = head_ref;
    while (temp != NULL){
        printf ("\t%d",temp->data);
        temp = temp->next;
    }
    printf ("\n");
}

int main()
{
    struct node *head_a = NULL;
    struct node *head_b = NULL;
    struct node *res = NULL;
    insert(&head_a,15);
    insert(&head_a,10);
    insert(&head_a,5);
    
    insert (&head_b, 20);
    insert (&head_b, 16);
    insert (&head_b, 8);
    
    printLL (head_a);
    printLL (head_b);
    
    res = sorted_merge (head_a, head_b);
    printLL (res);

    return 0;
}
