/******************************************************************************

                        power of 2 or not.
                        
0111  (x = 7 , x-1 = 6)                                            

(x && !(x & (x -1)));

(0111 && !(0111 & (0110)))
= (0111 && !(0110))
= (0111 && 0000)
= 0

1000 (x = 8, x-1 = 7)
(x && !(x & (x -1)));

(1000 && !(1000 & (0111)))
= (0111 && !(0000))
= (0111 && 0001)
= 1

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int isPowerOfTwo(int x)
    {
        // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
       return (x && !(x & (x - 1)));
    }
int main()
{
    int x =128;
    
    if(isPowerOfTwo(x) == 1 ){
        printf ("\n Given no is power of 2");
    }else {
        printf("\n given no is not a power of 2");
    }

    return 0;
}
