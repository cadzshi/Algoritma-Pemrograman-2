#include "head.h"

// Prosedur untuk memulai mesin karakter
void START(char pita[])
{
    // inisialisasi index dan karakter yang dibaca
    indeks = 0;
    cc = pita[indeks];
}


// Fungsi untuk memeriksa akhir dari proses (End of Process)
int EOP()
{
    // memeriksa apakah karakter saat ini merupakan simbol akhir dari pita
    if (cc == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Prosedur untuk memajukan karakter pada pita
void INC(char pita[])
{
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];
}


// Prosedur untuk memajukan karakter hingga melewati spasi
void ADV(char pita[])
{
    // menambah nilai indeks dan mengatur karakter yang dibaca
    indeks++;
    cc = pita[indeks];


    // Terus mengulang proses jika karakter saat ini masih berupa spasi
    while ((cc == ' ') && (EOP() == 0))
    {
        indeks++;
        cc = pita[indeks];
    }
}


// Fungsi untuk mendapatkan karakter pita saat ini
char GETCC()
{
    return cc;
}


// Fungsi untuk mendapatkan indeks pita saat ini
int GETINDEX()
{
    return indeks;
}
