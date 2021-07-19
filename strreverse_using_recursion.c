/******************************************************************************

                    string reverse without strrev and using recursion

*******************************************************************************/
#include <stdio.h>

void reverse (char str[], int s_index, int e_index){
     if (s_index < e_index){
        char tmp = str[e_index];
        str[e_index] = str[s_index];
        str[s_index] = tmp;
        reverse (str, s_index+1, e_index-1);
     }
     return;
}

int main()
{
    char str[] = "selva";
    int n = 5;
    void (*fp) (char*, int , int);
    fp = reverse;
    fp (str, 0, n-1);
    printf("\n Reversed string : %s", str);

    return 0;
}
