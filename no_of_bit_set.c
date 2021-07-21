//program to count no of bit set for all array element
#include <stdio.h>
#define IS_BIT_SET(n,k)  ((n & (1<<(k-1))) > 0) ? 1: 0

int main()
{
	int i, j, k, count=0, temp, bit_count =0;
	int arr[] = {5, 1 ,2 ,3};
	int n = sizeof (arr)/sizeof (arr[0]);
	
	for (i =0; i<n; i++){
	    bit_count =0;
	    temp = arr[i];
	    while (temp){
	        bit_count++;
	        temp = temp>>1;
	    }
	    //printf ("\n%d",bit_count);
	    for (k=1; k <= bit_count; k++){
	        if (arr[i] & (1<<(k-1))){
	            count++;
	        }
	    }
	    //printf ("\t%d", count);
	}
	printf ("%d", count);
	return 0;
}
