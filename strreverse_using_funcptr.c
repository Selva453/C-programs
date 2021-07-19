/******************************************************************************

                    string reverse without strrev and using function ptr

*******************************************************************************/
#include <stdio.h>

void reverse (char str[]){
    
    char *ptr = str;
    char *str1, *str2, temp;
    int i, len =0;
    
    while (*ptr!='\0'){
        ptr++;
        len++;
    }
    ptr = str;
    str1 = ptr;
    str2 = ptr;
    
    for (i =0; i< len-1; i++){
        str2++;
    }
    
    for (i = 0; i = len/2; i++){
        temp = *str2;
        *str1 = *str2;
        *str2 = temp;
        str1++;
        str2--;
    }
    printf ("\n Reversed string : %s", ptr);
    
}

int main (){
    char str[] = "selva";
    void (*fun_ptr) (char str[]) = &reverse;
    fun_ptr(str);
    return 0;
}
