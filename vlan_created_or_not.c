/* 0000 1000 0000 0000 0000 0000 0000 0000 = 134217728
    program to check vlan created or not
*/
#include <stdio.h>

void Is_vlan_created (int vlan_id, int arr[]){
    int idx = vlan_id / 32;
    int pos = (((idx+1) * 32) - vlan_id);
    
    if (arr[idx] & (1 << (pos-1)))
        printf ("vlan %d is already created", vlan_id);
    else
        printf ("vlan %d is not created", vlan_id);
        
    return;
}
int main()
{
    int arr[128];
    arr[3] = 134217728;
    Is_vlan_created (100, arr);
    return 0;
}
