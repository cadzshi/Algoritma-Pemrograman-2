
// memasukkan file header yang sudah dibuat sebelumnya
#include "head.h"

// memulai mesin
void start(char str[])
{
    idx = 0;       // inisialisasi index kalimat dengan 0 (awal kalimat)
    cc = str[idx]; // karakter pertama
}
void inc(char str[])
{
    idx++;         // memajukan satu indeks kalimat
    cc = str[idx]; // karakter saat ini diisi degan karakter pada indeks tersebut
}

int getidx() // mendapatkan nilai indeks saat ini
{
    return idx; // akan mereturn nilai indeks saat ini di variabel global
}

char getcc() // mendapatkan karakter saat ini
{
    return cc; // akan mereturn karakter saat ini pada variabel global
}

int eop() // menandakan akhir dari proses
{
    if (cc == '$') // ketika karakter saat ini adalah titik
        return 1;  // maka akan mereturn 1
    return 0;      // selain itu akan mereturn 0
}
void adv(char pita[])
{
    idx++;
    cc = pita[idx];

    while (cc == ' ' && eop() == 0)
    {
        idx++;
        cc = pita[idx];
    }
}