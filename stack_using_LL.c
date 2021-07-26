/******************************************************************************

                            stack implementation using LL

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};
int isStackEmpty(struct node **top){
    if (top == NULL)
        return 0;
    else 
        return 1;
    
}
void stack_push (struct node **top, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

void stack_peek (struct node *top){
    printf ("\nTop element : %d", top->data);
}

void stack_pop (struct node **top){
    if (isStackEmpty(top) == 0){
        printf ("\n Stack is empty...");
    }
    else{
        struct node *temp = *top;
    
        printf ("\nPoped element : %d", temp->data);
        *top = temp->next;
        temp->next = NULL;
        free(temp);
    }
    
    
}

int main () {
    struct node *top =NULL;
    stack_push(&top, 1);
    stack_push(&top, 2);
    stack_push(&top, 3);
    stack_push(&top, 4);
    //stack_peek(top);
    stack_pop(&top);
    //stack_peek(top);
    stack_pop(&top);
    stack_pop(&top);
    stack_pop(&top);
    stack_push(&top, 5);
    stack_peek(top);
    
    
   return 0; 
    
}
