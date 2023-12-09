#include "head.h"

int main ()
{
    int n;
    scanf("%d", &n);
    data barang[n];
    scandata(n, barang);

    print(n, barang);
}