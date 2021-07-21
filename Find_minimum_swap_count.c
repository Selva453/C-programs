#include <stdio.h>

int main()
{
    //int arr[] = {2, 4, 9, 8, 7, 9, 5, 1, 2, 3, 8};
    int arr[] = {2, 1, 5, 6, 3};
    //int arr[] = {2, 7 , 9 ,5 ,8 ,7 ,4};
    int arr_len = 0,
        left_min = 0,
        left_max = 0,
        right_min = 0,
        right_max = 0,
        key_position = -1,
        left_swap_count = 0,
        right_swap_count = 0,
        final_count = 0;
    int key = 0,
        i = 0;
   
    printf("\nEnter Key element : ");
    scanf("%d", &key);
   
    // Calculate array lenght
    arr_len = sizeof(arr)/sizeof(arr[0]);
    printf("\nArray Length : %d", arr_len);
   
    // Find Key position
    for(i=0; i<arr_len; i++)
    {
        if(arr[i] == key)
        {
            key_position = i;
            break;
        }
    }
    printf("\nKey position = %d", key_position);

    if(key_position == -1)
    {
        return 0;
    }
   
    // Find left side min and max
    for(i=0; i<=(key_position-1); i++)
    {
        if(arr[i]<key)
        {
            left_min++;
        }
        else if(arr[i]>key)
        {
            left_max++;
        }
    }
    printf("\nLeft side (min , max) : (%d , %d)",left_min, left_max);
   
    // Find right side min and max
    for(i=(key_position+1); i<arr_len; i++)
    {
        if(arr[i]<key)
        {
            right_min++;
        }
        else if(arr[i]>key)
        {
            right_max++;
        }
    }
    printf("\nRight side (min , max) : (%d , %d)",right_min, right_max);
   
    left_swap_count = (left_min>=right_max) ? left_min : right_max;
    printf("\nLeft Swap Count : %d", left_swap_count);
   
    right_swap_count = (left_max>=right_min) ? left_max : right_min;
    printf("\nRight Swap Count : %d", right_swap_count);
   
    final_count = (left_swap_count<=right_swap_count) ? left_swap_count : right_swap_count;
    printf("\n\n***********************");
    printf("\nMinimun swap count : %d", final_count);
    printf("\n***********************\n");
    return 0;
}
