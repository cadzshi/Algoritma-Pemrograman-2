#include "head.h"

int idx;
int wlen;
char cw[50];


// Prosedur untuk memulai mesin kata
void start(char str[])
{
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;
    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}


// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}


// Fungsi untuk memeriksa akhir dari proses
int eop(char str[])
{
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Prosedur untuk memajukan kata
void inc(char str[])
{
    // inisialisasi ulang panjang kata
    wlen = 0;
    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }
    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}


// Fungsi untuk mendapatkan panjang kata saat ini
int getlen()
{
    return wlen;
}


// Fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

void modify_data(char str[], student *data)
{
    // memulai mesin kata
    start(str);


    if (strcmp(getcw(), "INSERT") == 0)
    {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            strcpy(data->nim, getcw());
            inc(str);
            strcpy(data->nama, getcw());
            inc(str);
            strcpy(data->nilai, getcw());
        }
        else
        {
            // Error handling...
        }
    }
    else if (strcmp(getcw(), "UPDATE") == 0)
    {
        // Kode untuk mengubah/memodifikasi data...
    }
    else if (strcmp(getcw(), "DELETE") == 0)
    {
      // Kode untuk menghapus data...
    }
    else
    {
        // Error handling jika query DML tidak sesuai...
    }
}
