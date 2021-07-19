/******************************************************************************

                            Array Sorting by frequency
*******************************************************************************/

#include <stdio.h>

int main()
{
    int arr [] = {2, 4, 4, 3, 4, 2, 3, 1 ,2, 4};
    int count = 0, i, j, k;
    int n = sizeof(arr)/sizeof(arr[0]);
    int freq[10] = {0};
    
    for (i=0; i<n;i++){
        count =1;
        if (arr[i] != -1){
            for (j=i+1; j <n ; j++){
                if (arr[j] == arr[i]){
                    count++;
                    arr[j] = -1;
                }
            }
        freq[i] = count;
        }
    }
    printf ("\n Frequency sorted array...\n");
    for (j = n ; j >=0; j--){
        for (i=0; i< n; i++){
            if (j == freq[i]){
                for (k=0; k<j; k++)
                    printf ("\t%d", arr[i]);
            }    
        }
    }
    return 0;
}
