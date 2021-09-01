/******************************************************************************
                          star pyramid all functionalities
*******************************************************************************/

#include <stdio.h>
void full_pyramid (int n){
	
	int i, j,k;
	for (i =1; i <= n; ++i){
		k=0;
		for (j=1; j <= n-i; j++){
			printf (" ");
		}
		while (k != 2*i -1){
			printf("*");
			++k;
		}
		printf ("\n");
	}
}
void inverted_pyramid(int n){
    int i, j,k;
    for (i=n; i >=1; --i){
		for (j=1; j <= n-i; ++j){
			printf (" ");
		}
		for (k =i; k <= 2*i -1; ++k)
			printf ("*");
		for (k= 1; k < i; ++k)
		    printf("*");
		printf ("\n");
	}
}
int main()
{

    int n =4;
    //full_pyramid(n);
    inverted_pyramid(n);
    //printf("\n");
    full_pyramid(n);
    return 0;
}
