#include "head.h"

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
    if (str[idx] == '!')
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

void prosedur(int i, char pita[])
{
    int a;
    if (strcmp(getcw(), "BELI") == 0)
    {
        for (a = 0; a < 3; a++)
        {
            inc(pita);
            strcpy(tiket[banyakdata][a], getcw());
        }
        banyakdata++;
    }
    else if (strcmp(getcw(), "JUAL") == 0)
    {
        //YTTA
    }
    
}

void cariterpanjang(int i)
{
    int a, b;
    terpanjang[0] = 8;
    terpanjang[1] = 9;
    terpanjang[2] = 5;

    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < banyakdata; a++)
        {
            if (terpanjang[b] < strlen(tiket[a][b]))
            {
                terpanjang[b] = strlen(tiket[a][b]);
            }
        }
    }
}

void output(int i)
{
    cariterpanjang(banyakdata);
    int a, b;
    printf("~");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 8; a++)
    {
        printf("~");
    }
    printf("~\n");
    printf("! ID Tiket ");
    for (a = 0; a < terpanjang[0] - 8; a++)
    {
        printf(" ");
    }
    printf("! Deskripsi ");
    for (a = 0; a < terpanjang[1] - 9; a++)
    {
        printf(" ");
    }
    printf("! Harga ");
    for (a = 0; a < terpanjang[2] - 5; a++)
    {
        printf(" ");
    }
    printf("!\n");
    printf("~");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 8; a++)
    {
        printf("~");
    }
    printf("~\n");
    for (a = 0; a < banyakdata; a++)
    {
        printf("! %s ", tiket[a][0]);
        for (b = 0; b < terpanjang[0] - strlen(tiket[a][0]); b++)
        {
            printf(" ");
        }
        printf("! %s ", tiket[a][1]);
        for (b = 0; b < terpanjang[1] - strlen(tiket[a][1]); b++)
        {
            printf(" ");
        }
        printf("! %s ", tiket[a][2]);
        for (b = 0; b < terpanjang[2] - strlen(tiket[a][2]); b++)
        {
            printf(" ");
        }
        printf("!\n");
    }
    printf("~");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 9; a++)
    {
        printf("~");
    }
   
}