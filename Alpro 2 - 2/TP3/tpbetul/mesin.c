#include "header.h"

int f(int x)
{
    if (x == 0) return 2;       // jika x = 0, fungsi akan berhenti dan rekursif tidak dilanjutkan
    else if (x < 0) x *= -1;    // jika x bilangan negatif, ubah x menjadi bilangan positif

    return 2 * f(x - 1) + 5;    // jika x != 0, fungsi tidak akan berhenti dan akan melanjutkan rekursif
}

void divide(int a, int b)
{
    printf("%d ", a);               // print jumlah bahan bakar A
    if (a < 10) printf(" ");        // jika a angka satuan, print satu spasi tambahan
    printf(": %d ", b);             // print jumlah bahan bakar B
    if (b < 10) printf(" ");        // jika b angka satuan, print satu spasi tambahan
    printf("-> %d\n", f(a - b));    // print energi panas dari selisih

    if (a > 1 && b > 1)                 // selama a dan b belum ada yang bernilai 1
    {
        if (a >= b) divide(a / 3, b);   // jika a lebih besar atau sama dengan b, rekursif dengan mengurangi jumlah a
        else divide(a, b / 3);          // jika b lebih besar dari a, rekursif dengan mengurangi jumlah b
    }
}