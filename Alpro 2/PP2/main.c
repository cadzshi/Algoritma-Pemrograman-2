#include "head.h"

int main()
{
    scanf("%d %d", &baris, &kolom);
    data nama_matriks[baris][kolom];

    scandata (nama_matriks);
    printdata (nama_matriks);
}