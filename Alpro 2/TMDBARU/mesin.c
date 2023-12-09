#include "head.h"

void start(char word[])
{
    int i;

    // Set Nilai ke-0 dan string kosong
    for (i = 0; i < 4; i++)
    {
        query[i][0] = '\0';
    }
    for (i = 0; i < 3; i++)
    {
        tabel[i][0] = '\0';
    }
    for (i = 0; i < 4; i++)
    {
        value[i][0] = '\0';
    }
    idx = 0;
    wlen = 0;

    // While untuk melewati spasi
    while (word[idx] == ' ')
    {
        idx++;
    }

    // While untuk memasukkan kata ke dalam variabel cw(current word)
    while ((word[idx] != ' ') && (eop(word) == 0))
    {
        cw[wlen] = word[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';

    // Persiapan untuk prosedur exploade
    a = 0;
    b = 0;
    c = 0;
}

// Prosedur untuk mereset current word
void reset()
{
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk mengecek EOP
int eop(char query[])
{
    if (query[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk membaca kata selanjutnya
void inc(char query[])
{
    // Set ke-0
    wlen = 0;

    // While untuk melewati spasi
    while (query[idx] == ' ')
    {
        idx++;
    }

    // While untuk Memasukkan kata ke variabel cw
    while ((query[idx] != ' ') && (eop(query) == 0))
    {
        cw[wlen] = query[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata yang sedang dibaca
int getlen()
{
    return wlen;
}

// Fungsi untuk mendapatkan current word
char *getcw()
{
    return cw;
}

//Fungsi untuk melakukan COMPAREKATA antar string
int COMPAREKATA(char word1[], char word2[])
{
    int i = 0, flag = 0, panjangkata = 0;
    char huruf1, huruf2;
    /*
        (1) i = untuk indeks
        (2) flag = banyak kata yang sama
        (3) panjangkata = panjang kata kata terpanjang
        (4) huruf 1, huruf 2 = untuk menghindari error
    */

    // While yang digunakan untuk membandingkan kata
    while (word1[i] != '\0' || word2[i] != '\0')
    {
        // Proses menghindari error
        huruf1 = word1[i];
        huruf2 = word2[i];

        // Pemaksaan huruf menjadi kapital
        if (word1[i] >= 97)
        {
            huruf1 -= 32;
        }
        if (word2[i] >= 97)
        {
            huruf2 -= 32;
        }
        // Proses pembandingan
        if (huruf1 == huruf2)
        {
            flag++;
        }
        // Iterasi
        panjangkata++;
        i++;
    }

    // Membandingkan panjang flag dengan panjangkata
    if (panjangkata == flag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk mencopy kata (word 2 -> word 1)
void COPYKATA(char word1[], char word2[])
{
    // Variabel untuk indeks
    int i = 0;

    // While untuk mencopy kata
    while (word2[i] != '\0')
    {
        word1[i] = word2[i];
        i++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    word1[i] = '\0';
}




// Prosedur untuk mengambil record data
void ambildata()
{
    // Set ke-0
    int i = 0;
    banyakrecord[0] = 0;

    // Deklarasi file
    FILE *file;
    file = fopen("tumkm.dat", "r");

    // Memindahkan record ke variabel
    fscanf(file, "%s %s %s", umkm[i].value[0], umkm[i].value[1], umkm[i].value[2]);

    // While untuk memindahkan record ke variabel
    while (COMPAREKATA(umkm[i].value[0], "####") == 0)
    {
        i++;
        banyakrecord[0]++;
        fscanf(file, "%s %s %s", umkm[i].value[0], umkm[i].value[1], umkm[i].value[2]);
    }
    // Menutup file
    fclose(file);
}

// Prosedur untuk memecah pita masukkan user
void explode(char word1[])
{
    int tanda = 0;
    // Proses pemecahan pita;
    while (tanda == 0)
    {
        // Kata masuk ke dalam kategori query
        if ((COMPAREKATA(getcw(), "ISI") == 1) || (COMPAREKATA(getcw(), "UBAH") == 1) || (COMPAREKATA(getcw(), "HAPUS") == 1) || (COMPAREKATA(getcw(), "TAMPIL") == 1))
        {
            COPYKATA(query[a], getcw());
            a++;
        }
        // Kata masuk ke dalam kategori tabel
        else if (COMPAREKATA(getcw(), "tumkm") == 1)
        {
            COPYKATA(tabel[b], getcw());
            b++;
        }
        // Kata masuk ke dalam kategori value
        else
        {
            COPYKATA(value[c], getcw());
            c++;
        }
        tanda = 1;
    }
}

// Prosedur untuk mencari kata terpanjang
void FINDLONGEST()
{
    // Variabel untuk indeks
    int i, j;

    // Set kata terpanjang pertama sepanjang judul tabel
    longeststr[0][0] = 7;
    longeststr[0][1] = 10;
    longeststr[0][2] = 7;

    // Proses pencarian kata terpanjang
    for (i = 0; i < banyakrecord[0]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (longeststr[0][j] < strlen(umkm[i].value[j]))
            {
                longeststr[0][j] = strlen(umkm[i].value[j]);
            }
        }
    }

    
}

// Query ISI (memasukkan data ke tabel atau file)
int ISI()
{
    // (1) i, j = untuk indeks | (2) flag = tanda ada atau tidaknya record yang dimasukkan
    int i, j;

    // Deklarasi File
    FILE *file;
    // Jika user memasukkan tabel tumkm
    file = fopen("tumkm.dat", "w");
    // Proses pemasukkan data
    for (i = 0; i < banyakrecord[0]; i++)
    {
        fprintf(file, "%s %s %s\n", umkm[i].value[0], umkm[i].value[1], umkm[i].value[2]);
    }
    fprintf(file, "%s %s %s\n", value[0], value[1], value[2]);

    printf("\n  -------------------------");
    printf("\n[ DATA BERHASIL DITAMBAHKAN ]\n");
    printf("  -------------------------\n");

    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
      
    printf("| ID UMKM ");
    for (i = 0; i < longeststr[0][0] - 7; i++)
    {
        printf(" ");
    }
    printf("| Nama Usaha ");
    for (i = 0; i < longeststr[0][1] - 10; i++)
    {
        printf(" ");
    }
    printf("| Pemilik ");
    for (i = 0; i < longeststr[0][2] - 7; i++)
    {
        printf(" ");
    }
    printf("|\n");
    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
    

    // Proses ngeprint data tabel
    for (j = 0; j < 1; j++)
    {
        printf("| %s ", value[0]);
        for (i = 0; i < longeststr[0][0] - strlen(value[0]); i++)
        {
            printf(" ");
        }
        printf("| %s ", value[1]);
        for (i = 0; i < longeststr[0][1] - strlen(value[1]); i++)
        {
            printf(" ");
        }
        printf("| %s ", value[2]);
        for (i = 0; i < longeststr[0][2] - strlen(value[2]); i++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    // Proses nge-print penutup tabel
    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
    // Penambahan EOF
    fprintf(file, "#### #### ####\n");
    // Menutup file
    fclose(file);
    
    return 1;
}

// Query tampil (Menampilkan tabel)
int TAMPIL()
{
    // Untuk indeks
    int i, j, k, l;
    // Proses ngeprint bagian header tabel
    printf("\n  ---------------");
    printf("\n[ DATA TABEL UMKM ]");
    printf("\n  ---------------\n");

    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
      
    printf("| ID UMKM ");
    for (i = 0; i < longeststr[0][0] - 7; i++)
    {
        printf(" ");
    }
    printf("| Nama Usaha ");
    for (i = 0; i < longeststr[0][1] - 10; i++)
    {
        printf(" ");
    }
    printf("| Pemilik ");
    for (i = 0; i < longeststr[0][2] - 7; i++)
    {
        printf(" ");
    }
    printf("|\n");
    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
    

    // Proses ngeprint data tabel
    for (j = 0; j < banyakrecord[0]; j++)
    {
        printf("| %s ", umkm[j].value[0]);
        for (i = 0; i < longeststr[0][0] - strlen(umkm[j].value[0]); i++)
        {
            printf(" ");
        }
        printf("| %s ", umkm[j].value[1]);
        for (i = 0; i < longeststr[0][1] - strlen(umkm[j].value[1]); i++)
        {
            printf(" ");
        }
        printf("| %s ", umkm[j].value[2]);
        for (i = 0; i < longeststr[0][2] - strlen(umkm[j].value[2]); i++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    // Proses nge-print penutup tabel
    garis_tabel(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
    
    return 1;
}

void garis_tabel (int u, int n, int p)
{
    printf("+-");
    for (int i = 0; i < u; i++) 
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < n; i++) 
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < p; i++) 
    {
        printf("-");
    }
    printf("-+\n");
}