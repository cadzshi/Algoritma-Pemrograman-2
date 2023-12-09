// Library:
#include <stdio.h>
#include <string.h>

// Variabel Global untuk indeks
int i, j, k;

typedef struct
{
    char nama[100];
    int harga;
    char toko[100];
    int kalori;
    /*
        (1) nama = nama makanan
        (2) harga = harga makanan
        (3) toko = toko makanan
        (4) kalori = kalori makanan
    */
} dmakanan;

// Prosedur untuk sorting menggunakan selection sort
void sorting(dmakanan data[], int n, char urut[]);
// Prosedur untuk melakukan search menggunakan binary search
void search(dmakanan data[], int n, int cari, char urut[]);