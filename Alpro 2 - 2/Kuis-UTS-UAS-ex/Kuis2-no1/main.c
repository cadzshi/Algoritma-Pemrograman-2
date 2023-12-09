#include "head.h"

int main()
{
    dmakanan data[51];
    int n, cari;
    char urut[10];
    /*
        (1) n = banyak data
        (2) cari = data yang ingin dicari
        (3) urut = urutan berdasarkan apa
    */
    // Meminta inputan banyaknya data
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        // Meminta inputan data-data makanan
        scanf("%s %d %s %d", &data[i].nama, &data[i].harga, &data[i].toko, &data[i].kalori);
    }

    // Meminta inputan dasar urutan dan data yang akan dicari
    scanf("%s %d", &urut, &cari);

    // Pemanggilan prosedur sorting dan searching
    sorting(data, n, urut);
    search(data, n, cari, urut);

    return 0;
}