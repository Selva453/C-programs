/******************************************************************************

                           bitwise using macro

*******************************************************************************/

#include <stdio.h>
#define SET_BIT(n,k) n|(1<<(k-1))
#define CLEAR_BIT(n,k) n&(~(1<<(k-1)))
#define TOGGLE(n,k) n^(1<<(k-1))
#define IS_BIT_SET(n,k)  ((n&(1<<(k-1))) > 0) ? "YES" : "NO"

int main (){
    int n=0, k =0;
    
    printf ("\nEnter any no...\n");
    scanf ("%d", &n);
    
    printf ("\nEnter position..\n");
    scanf ("%d", &k);
    
    /*printf ("\nNo after setting the bit : %d", (SET_BIT(n,k)));
    printf ("\nNo after clearing the bit : %d", (CLEAR_BIT(n,k)));
    printf ("\nNo after Toggling the bit : %d", (TOGGLE(n,k)));*/
    printf ("\nBit at %d postion is SET : %s", k,(IS_BIT_SET(n,k)));
    

    return 0;
}
