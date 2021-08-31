/******************************************************************************

                            Binary search tree

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

static int count = 0;
//int depth =0;

struct node {
    int data;
    struct node *left, *right;
};

struct node *create_newnode(int key){
    //printf("1");
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right= NULL;
    return new_node;
}

struct node* insert(struct node* root, int key){
    
    if(root == NULL)
    {
        root = create_newnode(key);
        return root;
    }
    
    if(key<root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key>root->data)
    {
        root->right = insert(root->right, key);   
    }
    else
    {
        printf("entered key already exist\n");
    }
    
    return root;
}

void print_inorder(struct node *node){
    if (node != NULL){
        count++;
        print_inorder(node->left);
        printf ("%d\t", node->data);
        print_inorder(node->right);
    }
}

void print_preorder(struct node* node){
    if (node != NULL){
        printf("%d\t",node->data);
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

void print_postorder(struct node * node){
    if (node != NULL){
        print_postorder(node->left);
        print_postorder(node->right);
        printf ("%d\t",node->data);
    }
}

int find_Depth (struct node *root){
    if (root == NULL){
        return 0;
    }
    int left_len =0 , right_len =0;
    left_len = find_Depth(root->left);
    right_len = find_Depth(root->right);
    
    if (left_len > right_len){
        return (left_len+1);
    } else {
        return (right_len+1);
    }
}

int main()
{
    struct node *root = NULL;
    int i, n, key, depth=0;
    printf ("\n Enter the no of element to be inserted...\n");
    scanf("%d",&n);
    printf ("\n Enter the elements...\n");
    for (i =0; i <n; i++){
        scanf ("%d", &key);
        root = insert(root, key);
    }
    
    printf("\n In Oder : ");
    print_inorder(root);
    printf("\n Pre Oder : ");
    print_preorder(root);
    printf("\n Post Oder : ");
    print_postorder(root);
    
    depth = find_Depth(root);
    printf ("\n The Depth of the tree is : %d", depth);

    return 0;
}
