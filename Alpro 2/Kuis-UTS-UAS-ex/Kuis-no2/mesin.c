#include "header.h" //panggil header
void r(int a, int b, int c, int n)
{
    if (n > 0) // jika n>0
    {
        printf("%d %d %d ", a, b, c);  // print dulu nilainya lalu diakhir spasi
        r(a, b * b, b * b + c, n - 1); // lalu panggil rekursi, untuk a angkanya tetap sehingga tidak perlu diganti
        // untuk b, itu dikalikan angkanya sendiri, dan yang c adalah hasil perkalian b*b atau disebut dengan angka sebelumnya deret ke 3 tambah c
    }
    else if (n == 0)
    {
        printf("%d %d %d\n", a, b, c); // ini kondisi ketika n==0 atau rekursi terakhir, jadi print newline
    }
}