#include "head.h"

void scandata(int n, data barang[])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", &barang[i].nama, &barang[i].berat, &barang[i].nilaiguna);
    }
}

void print(int n, data barang[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", barang[i].nama, barang[i].berat, barang[i].nilaiguna);
    }
}