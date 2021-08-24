/******************************************************************************
                        decimal_to_binary convertion
                            
*******************************************************************************/

#include <stdio.h>

void decimal_to_binary (int decimal_num){
    int binary_num[32], i = 0;
    
    while (decimal_num >0){
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    printf ("\nbinary num = ");
    for (int j = i -1; j >=0; j--)
        printf ("%d",binary_num[j]);
    
    return;
}

int main()
{
    int decimal_num;
    printf("Decimal to binary converter:-");
    printf("\n=========================");
    
    printf ("\n\n Enter any deciaml no :");
    scanf ("%d", &decimal_num);
    
    decimal_to_binary(decimal_num);
    

    return 0;
}


