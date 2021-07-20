/******************************************************************************

                          Merge two arrays and sorting

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
    int i, j, k = 0;
    int *tmp = NULL;
    tmp = (int*) malloc (n1 * sizeof (int));
    for (i =0; i < n1; i++)
        tmp[i] = arr1[i];
    arr1 = (int*) realloc (arr1, ((n1+n2)*sizeof(int)));
    i = 0, j =0, k =0;
    while (i < n1 && j <n2){
        if (tmp[i] < arr2[j]){
            arr1[k] = tmp[i];
            i++;
            k++;
        }else {
            arr1[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n1){
        arr1[k] = tmp[i];
        i++;
        k++;
    }
    while (j < n2){
        arr1[k] = arr2[j];
        j++;
        k++;
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
