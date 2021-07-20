/******************************************************************************

                           Set /clear/ toggle bitwise operation

*******************************************************************************/

#include <stdio.h>

int setbit (int n, int k){
    return (n | 1<<(k -1));
}

int clearbit (int n, int k){
    return (n & (~(1<<(k-1))));
}

int togglebit(int n, int k){
    return (n ^ (1<<(k-1)));
}

int main()
{
    int n, k, option, res =0;
    printf("\nEnter any no: ");
    scanf ("%d", &n);
    printf ("\nSelect any option,");
    printf ("\n1.set      2.clear     3.toggle\n");
    scanf("%d", &option);
    
    printf ("\nEnter the position you want to set/clear/toggle\n");
    scanf ("%d", &k);
    
    switch (option){
        case 1:
            res = setbit(n,k);
        break;
        case 2:
            res = clearbit(n,k);
        break;
        case 3:
            res = togglebit(n,k);
        break;
        default:
            printf ("\nEnter valid option");
    }
    printf ("\nResult = %d",res);

    return 0;
}
