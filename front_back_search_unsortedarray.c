/******************************************************************************
                    Front back search in unsorted array
*******************************************************************************/

#include <stdio.h>

int isKeyFound (int arr[], int n, int key){
    int start_idx = 0;
    int end_idx = n -1;
    
    while (start_idx <= end_idx){
        if (arr[start_idx] == key || arr[end_idx] == key)
            return 1;
        start_idx++;
        end_idx--;
    }
    return 0;
}

int main (){
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
   int x = 1300;
   int n = sizeof(arr)/sizeof(arr[0]);
   if (isKeyFound(arr,n,x)) 
        printf ("Element found...");
    else
        printf ("Element not found...");
}
