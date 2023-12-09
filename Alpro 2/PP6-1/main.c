#include "head.h"

int main()
{
    int i, j;
    int k, l, m;

    scanf("%d", &k);
    data arr1[k];
    scandata(arr1, k);

    scanf("%d", &l);
    data arr2[l];
    scandata(arr2, l);

    scanf("%d", &m);
    data arr3[m];
    scandata(arr3, m);
    
    sorting(arr1, k);
    sorting(arr2, l);
    sorting(arr3, m);

    data arr12[k + l];
    merge(arr1, k, arr2, l, arr12);

    data arr123[k + l + m];
    merge(arr12, k + l, arr3, m, arr123);

    printdata(arr123, k  + l + m);
    return 0;
}