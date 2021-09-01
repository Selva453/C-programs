/******************************************************************************
                    finding Middle Node in LL
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};
int getNodeCount (struct node *head_ref);

void getMiddleNode (struct node *head1){
    struct node *ptr1 = head1;
    struct node *ptr2 = head1;
    
    while (ptr1 != NULL && ptr1->next != NULL){
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    /*int c = getNodeCount (head1);
    for (int i =0; i < c/2; i++){
        ptr2 = ptr2->next;
    }*/
    printf ("\t%d", ptr2->data);
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
   struct node *newnode;
   struct node *head1 = (struct node *)malloc(sizeof (struct node));
   head1->data = 2;
   
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 3;
   head1->next = newnode;
   
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 4;
   head1->next->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 15;
   head1->next->next->next = newnode;
   
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = 30;
   head1->next->next->next->next = newnode;
   
   printLL(head1);
   
   getMiddleNode (head1);

    return 0;
}
