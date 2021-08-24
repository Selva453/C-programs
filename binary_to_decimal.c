/******************************************************************************
                        binary_to_decimal convertion
                            
*******************************************************************************/

#include <stdio.h>

void binary_to_decimal (int binary_num){
    int decimal_num = 0, n = binary_num, rem, base =1;
    
    while (n >0){
        rem = n % 10;
        decimal_num = (decimal_num + (base * rem));
        n = n / 10;
        base = base * 2;
        
    }
    printf ("\ndecimal num = %d", decimal_num);
    
    return;
}

int main()
{
    int binary_num;
    printf("Binary to decimal converter:-");
    printf("\n=========================");
    
    printf ("\n\n Enter any binary no :");
    scanf ("%d", &binary_num);
    
    binary_to_decimal(binary_num);
    

    return 0;
}


