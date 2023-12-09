#include "head.h"

int main()
{
    //scan baris kolom
    int n, m;
    scanf("%d %d", &n, &m);
    //panggil prosedur
    scanmatriks(m, n);
    printmatriksawal(m, n);
    return 0;
}