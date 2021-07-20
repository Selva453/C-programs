/******************************************************************************

                          Merge two arrays

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void printarray (int *arr1, int n){
    int i;
    printf ("\nThe array elements are...\n");
    for (i =0 ; i < n; i++){
        printf ("\t%d", arr1[i]);
    }    
}
void Merge (int *arr1, int*arr2, int n1, int n2){
    int i, j;
    arr1 = (int*) realloc (arr1, (n1+n2));
    for (i=n1,j=0; i < (n1+n2); i++, j++){
            *(arr1+i) = *(arr2+j);
    }
    printarray (arr1, (n1+n2));
}

int main()
{
    int n, m, i;
    int *arr1, *arr2;
    
    printf("\nEnter the arr1 size ");
    scanf ("%d",&n);
    
    printf("\nEnter the arr2 size ");
    scanf ("%d",&m);
    
    arr1 = (int *) calloc (n, sizeof(int));
    printf ("\nEnter arr1 values ");
    for (i =0; i < n; i++){
        scanf ("%d", (arr1+i));
    }
    arr2 = (int *) calloc (m, sizeof(int));
    printf ("\nEnter arr2 values ");
    for (i =0; i < m; i++){
        scanf ("%d", (arr2+i));
    }
    Merge (arr1, arr2, n, m);
    //printarray (arr1, n);
    //printarray (arr2, m);
    return 0;
}
