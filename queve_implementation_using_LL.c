/******************************************************************************

                          Queve implementation using LL

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct que {
    int count;
    struct node *rear, *front;
};

void print_que (struct node *head){
    if (head != NULL){
        printf ("%d ", head->data);
        head = head->next;
        print_que(head);
    }
    return;
}
void intialize(struct que *q){
    q->rear = NULL;
    q->front = NULL;
    q->count = 0;
}

void enqueve (int data, struct que *q){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear  == NULL){
       q->rear = temp;
       q->front = temp;
       q->count++;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    q->count++;
    
}

int dequeve (struct que* q){
    if (q->front == NULL){
        printf ("Queve is empty...\n");
        return 0;
    }
    int n = q->front->data;
    struct node *temp = q->front;
    
    q->front = q->front->next;
    free(temp);
    q->count--;
    
    return n;
}

int main()
{
    struct que *q = (struct que*)malloc(sizeof (struct que));
    intialize(q);
    
    enqueve (10, q);
    enqueve (20, q);
    enqueve (30, q);
    enqueve (40, q);
    
    print_que(q->front);
    //printf ("\n front : %d", q->front->data);
    //printf ("\n rear : %d", q->rear->data);
   printf ("\n dequed element = %d\n", dequeve(q));
   printf ("\n dequed element = %d\n", dequeve(q));
   printf ("\n dequed element = %d\n", dequeve(q));
   //printf ("\n dequed element = %d\n", dequeve(q));
   print_que(q->front);

    return 0;
}
