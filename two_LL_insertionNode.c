/******************************************************************************

                           Two LL insertionNode or merge point.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};
int getNodeCount (struct node *head_ref);
int insertionNode (int d, struct node *head1, struct node *head2);


int getInsertionNode (struct node *head1, struct node *head2){
    int c1 = getNodeCount(head1);
    int c2 = getNodeCount(head2);
    int d;
    
    printf ("\n c1 = %d and c2 = %d", c1, c2);
    if (c1 > c2) {
        d = c1 - c2;
        return insertionNode(d, head1, head2);
    } else {
        d = c2 - c1;
        return insertionNode(d, head2, head1);
    }
}

int insertionNode (int d, struct node *head1, struct node *head2){
    struct node *current1 = head1;
    struct node *current2 = head2;
    int i;
    
    for (i =0; i < d; i++){
        if (current1 == NULL){
            return -1;
        }
        current1 = current1->next;
    }
    while (current1 != NULL && current2 != NULL){
        if (current1 == current2){
            return current1->data;
            //return current2->data;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return -1;
}

int getNodeCount (struct node *head_ref){
    int count = 0;
    struct node *temp = head_ref;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
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
    //LL 1 -> 2 3 4 15 30
    //LL 2 -> 6 5 15 30
   struct node *newnode;
   struct node *head1 = (struct node *)malloc(sizeof (struct node));
   head1->data = 2;
   
   struct node *head2 = (struct node *)malloc (sizeof(struct node));
   head2->data = 6;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 3;
   head1->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 5;
   head2->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 4;
   head1->next->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 15;
   head2->next->next = newnode;
   head1->next->next->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 30;
   head2->next->next->next = newnode;
   head1->next->next->next->next = newnode;
   
   printLL(head1);
   printLL(head2);
   
   printf ("\n The insertion node is %d", getInsertionNode (head1, head2));

    return 0;
}
