#include "header.h"
void swap(data *a, data *b)
{
    data temp; // inisialisasi temp untuk tempat menyimpan data
    temp = *a; // simpan a di temp dulu
    *a = *b;   // a= b
    *b = temp; // b=temp atau b=a
}
void ss(int n, data temp[]) // selection sort untuk harga
{
    int index, i, j;            // deklarasi index
    for (i = 0; i < n - 1; i++) // lalu ini for dengan batas n-1 karena nanti j nya ada j+1 agar tidak lebih
    {
        index = i; // simpan i di index
        for (j = i + 1; j < n; j++)
        {
            if (temp[index].harga > temp[j].harga) // jika harga i lebih dari nim j maka index= j
            {
                index = j;
            }
        }
        swap(&temp[index], &temp[i]); // tuker index dengan i, jika tidak masuk di kondisi tadi maka tidak akan terjadi apa apa
    }
}
void ss2(int n, data temp[]) // selection sort untuk kalori
{
    int index, i, j;            // deklarasi index
    for (i = 0; i < n - 1; i++) // lalu ini for dengan batas n-1 karena nanti j nya ada j+1 agar tidak lebih
    {
        index = i; // simpan i di index
        for (j = i + 1; j < n; j++)
        {
            if (temp[index].kalori < temp[j].kalori) // jika kalori i lebih dari nim j maka index= j
            {
                index = j;
            }
        }
        swap(&temp[index], &temp[i]); // tuker index dengan i, jika tidak masuk di kondisi tadi maka tidak akan terjadi apa apa
    }
}
void binSearch(data dataa[], int n, int cari)
{
    // nyari data
    // deklarasi variabel
    int i = 0, k = 0, found = 0;
    while ((i <= n) && (found == 0))
    {
        k = (int)((i + n) / 2);     // bagi dua dulu
        if (cari == dataa[k].harga) // kalo langsung nemu, found=1
        {
            found = 1;
        }
        else // kalo belum
        {
            if (cari < dataa[k].harga) // kalo lebih besar, ke kiri(kurangi)
            {
                n = k - 1;
            }
            else // kalo engga, tambah ke kanan
            {
                i = k + 1;
            }
        }
    }
    if (found == 1) // jika ketemu print datanya
    {
        printf("nama makanan: %s\n", dataa[k].nama);
        printf("harga: %d\n", dataa[k].harga);
        printf("tempat penjualan: %s\n", dataa[k].tempat);
        printf("persen kalori: %d\n", dataa[k].kalori);
    }
    else // jika tidak, print tidak ketemu
    {
        printf("tidak ditemukan\n");
    }
}
void binSearch2(data dataa[], int n, int cari)
{
    // nyari data yaaa
    int i = 0, k = 0, found = 0;
    while ((i <= n) && (found == 0))
    {
        k = (int)((i + n) / 2);      // bagi dua dulu
        if (cari == dataa[k].kalori) // kalo langsung nemu, found=1
        {
            found = 1;
        }
        else // kalo belum
        {
            if (cari > dataa[k].kalori) // kalo lebih kecil, ke kiri(kurangi)
            {
                n = k - 1;
            }
            else // kalo engga, tambah ke kanan
            {
                i = k + 1;
            }
        }
    }
    if (found == 1) // jika ketemu print datanya
    {
        printf("nama makanan: %s\n", dataa[k].nama);
        printf("harga: %d\n", dataa[k].harga);
        printf("tempat penjualan: %s\n", dataa[k].tempat);
        printf("persen kalori: %d\n", dataa[k].kalori);
    }
    else // jika tidak, print tidak ketemu
    {
        printf("tidak ditemukan\n");
    }
}
