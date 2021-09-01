/*******************************************************************************************************
                        optmized_binary_search
                        
In normal binary search, we need to know the array bounds (start_idx and end_idx)
but in some cases array will have infinite element, so for such case normal binary
search algo won't work.
So in order to find position of key, first we find bounds and then apply binary search algorithm.
Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with 
high index element, 
->if it is greater than high index element then copy high index in low index and double the high index. 
->if it is smaller, then apply binary search on high and low indices found. 
********************************************************************************************************/

#include <stdio.h>

int binary_search (int arr[], int start_idx, int end_idx, int key){
    if (start_idx <= end_idx){
        int mid = start_idx + (end_idx - start_idx)/2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key) 
            return binary_search(arr, mid+1, end_idx, key);
        else if (arr[mid] > key)
            return binary_search(arr, start_idx, mid -1, key);
    }
    return -1;
}

int optmized_binary_search(int arr[], int key){
    int l = 0;
    int h = 1;
    int val = arr[0];
    
    while (val < key){
        l = h;
        h = 2*h;
        val = arr[h];
    }
    return binary_search(arr, l, h, key);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int res = optmized_binary_search (arr, 101);
    if (res == -1)
        printf ("\n Element not found...");
    else
        printf ("\n Element fount at idx [%d]", res);
    return 0;
}
