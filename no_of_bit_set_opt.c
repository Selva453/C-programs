/******************************************************************************

                        program to count no of 1s.
                        
n=7
while (0111){
 n = (0111) & (0110)
 n = 0110
 count = 1;
}

while (0110)
{
n = (0110  & (0101))
n = 0100
count =2
}

while (0100)
 n =  0100 & (0011)
  = 0
count =3

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
int count = 0;

int set_bit_count (int n){
    while (n){
        n = n & (n-1);
        count++;
    }
    return count;
}
int main()
{
    int x =6;
    
    printf ("\n No of bits set = %d", set_bit_count(x));
    
    
    return 0;
}
