/******************************************************************************

                          sorting all functionalities

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
void swap (int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void buble_sort (int arr[], int n){
    int i, j;
    for (i=0; i <n-1; i++){
        for (j=0; j <n-1-i; j++){
            if (arr[j] > arr[j+1]){
                swap (&arr[j], &arr[j+1]);
            }
        }
    }
    printarray (arr, n);
}
void selection_sort(int arr[], int n){
    int i,j, min_idx;
    for (i =0; i< n-1; i++){
        min_idx = i;
        for (j = i+1; j <n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap (&arr[min_idx], &arr[i]);
    }
    printarray (arr, n);
}
void insertion_sort(int arr[], int n){
    int i, j ,key;
    for (i=1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = key;
    }
    printarray (arr, n);
}
void merge (int arr[], int low, int mid, int high){
    int n1 = mid - low +1, n2 = high - mid, i,j,k;
    int l[n1], r[n2];
    for (i =0; i < n1; i++)
        l[i] = arr[low+i];
    for (j=0; j< n2; j++)
        r[j] = arr[mid+1+j];
    i =0;
    j =0;
    k = low;
    while (i < n1 && j < n2){
        if (l[i] <= r[j]){
            arr[k] = l[i];
            i++;
            k++;
        }else {
            arr[k] = r[j];
            j++;
            k++;
        }
    }
    while (i < n1){
        arr[k] = l[i];
        k++;
        i++;
    }
    while (j < n2){
        arr[k] = r[j];
        k++;
        j++;
    }
}
void merge_sort (int arr[], int low, int high){
    if (low < high){
        int mid = low + (high - low)/2;
        merge_sort (arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge (arr, low, mid, high);
    }
}
int partition(int arr[], int low, int high){
    int i ,j;
    int pivot = arr[high];
    i = low -1;
    for (j = low; j <= high; j++){
        if (arr[j] < pivot){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i+1], &arr[high]);
    return (i+1);
}
void quick_sort(int arr[], int low, int high){
    if (low < high){
        int pi = partition (arr, low, high);
        //printf ("\nPartition element = %d", pi);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}
void frequency_sort (int arr[], int n){
    int freq[n];
    int i , j ,k, count =1;
    
    for (i =0 ; i < n; i++){
        freq[i] = 0;
        if (arr[i] != -1){
            for (j=i+1; j<n; j++){
                if (arr[i] == arr[j]){
                    count++;
                    arr[j] = -1;
                }
            }
            freq[i] = count;
            count = 1;
        }
    }
    //printarray (freq, n);
    printf ("\nFrequency sorted array is ...\n");
    for (i =0; i < n; i++){
        if (freq[i] != 0){
            for (j=0; j < freq[i]; j++){
                printf (" %d", arr[i]);
            }
        }
    }
    
}
int main (){

//int arr[] = {2, 1, 8, 3, 6, 5, 4, 7};
int arr[] = {2, 3, 4, 2, 3, 2, 1, 2, 5};
int n = sizeof(arr) / sizeof (arr[0]);
int option;

printf ("\nEnter your choise...");
printf ("\n1.buble sort         2.selection sort");
printf ("\n3.insertion sort     4.merge sort");
printf ("\n5.quick sort         6.frequency sort\n");
scanf ("%d", &option);

switch (option){
    case 1:
        buble_sort (arr, n);
    break;
    case 2:
        selection_sort (arr, n);
    break;
    case 3:
        insertion_sort (arr, n);
    break;
    case 4:
        merge_sort (arr, 0, n-1);
        printarray (arr, n);
    break;
    case 5:
        quick_sort (arr, 0, n-1);
        printarray (arr, n);
    break;
    case 6:
        frequency_sort (arr, n);
    break;
    default:
    printf ("\nEnter valid option");
    break;
}
    return 0;
}
