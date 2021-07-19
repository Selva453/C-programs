
/******************************************************************************

                          Number pyramid


*******************************************************************************/

#include <stdio.h>

int main()
{

    int n;
    int count =1;
    int m , l, i ,j;
    
    printf ("\nEnter the row no..");
    scanf ("%d", &n);
    

    for (i =0 ; i < n; i++){
        for (j =0; j < n -i; j++){
            printf (" ");
        }
		for (m =0; m <=i; m++){
		    printf ("%d", count);
		    count++;
		}
		count = count -2;
		for (l = 0; l <= i -1; l++){
		    printf ("%d", count);
		    count--;
		}
		printf ("\n");
		count =1;
    }
return 0;
}
