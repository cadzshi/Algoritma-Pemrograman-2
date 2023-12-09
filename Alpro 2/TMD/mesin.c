#include "head.h"

//prosedur memulai mesin kata
void STARTKATA(char str[])
{
    int i;

    // Set Nilai ke-0 dan string kosong
    i = 0;
    while (i < 4)
    {
        query[i][0] = '\0';
        i++;
    }
    i = 0;
    while (i < 3)
    {
        tabel[i][0] = '\0';
        i++;
    }
    i = 0;
    while (i < 4)
    {
        record[i][0] = '\0';
        i++;
    }
    idx = 0;
    wlen = 0;
    // While untuk melewati spasi
    while (str[idx] == ' ')
    {
        idx++;
    }

    // While untuk memasukkan kata ke dalam variabel cw(current word)
    while ((str[idx] != ' ') && (EOPKATA(str) == 0))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';

    // Set nilai untuk prosedur PISAHKATA
    a = 0;
    b = 0;
    c = 0;
}

// Prosedur untuk mereset current word
void RESETKATA()
{
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk mengecek EOP
int EOPKATA(char input[])
{
    if (input[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk membaca kata selanjutnya
void INCKATA(char input[])
{
    // Set ke-0
    wlen = 0;

    // While untuk melewati spasi
    while (input[idx] == ' ')
    {
        idx++;
    }

    // While untuk Memasukkan kata ke variabel cw
    while ((input[idx] != ' ') && (EOPKATA(input) == 0))
    {
        cw[wlen] = input[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata yang sedang dibaca
int GETLEN()
{
    return wlen;
}

// Fungsi untuk mendapatkan current str
char *GETCW()
{
    return cw;
}

//Fungsi untuk melakukan compare antar string
int COMPAREKATA(char str1[], char str2[])
{
    //deklarasi variabel
    int i = 0, flag = 0, panjangkata = 0;   //indeks, penanda
    char huruf1, huruf2;                    //untuk membandingkan
    
    // While yang digunakan untuk membandingkan kata
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        huruf1 = str1[i];
        huruf2 = str2[i];

        // Merubah huruf menjadi kapital
        if (str1[i] >= 97)
        {
            huruf1 -= 32;
        }
        if (str2[i] >= 97)
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
        return 1;   //jika sama
    }
    else
    {
        return 0;   
    }
}

// Prosedur untuk mencopy kata (str 2 -> str 1)
void COPYKATA(char str1[], char str2[])
{
    int i = 0;  //indeks

    // While untuk mencopy kata
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    str1[i] = '\0';
}

// Prosedur untuk mengambil record data
void AMBILDATA()
{
    // Set ke-0
    int i = 0;
    banyakdata[0] = 0;
    banyakdata[1] = 0;

    // Deklarasi file
    FILE *file;
    file = fopen("tumkm.dat", "r");

    // Memindahkan record ke variabel
    fscanf(file, "%s %s %s", umkm[i].record[0], umkm[i].record[1], umkm[i].record[2]);

    // While untuk memindahkan record ke variabel
    while (COMPAREKATA(umkm[i].record[0], "####") == 0)
    {
        i++;
        banyakdata[0]++;
        fscanf(file, "%s %s %s", umkm[i].record[0], umkm[i].record[1], umkm[i].record[2]);
    }
    // Menutup file
    fclose(file);

    // Set ke-0
    i = 0;
    // Deklarasi file
    file = fopen("tpembeli.dat", "r");

    // Memindahkan record ke variabel
    fscanf(file, "%s %s %s", pembeli[i].record[0], pembeli[i].record[1], pembeli[i].record[2]);

    // While untuk memindahkan record ke variabel
    while (COMPAREKATA(pembeli[i].record[0], "####") == 0)
    {
        i++;
        banyakdata[1]++;
        fscanf(file, "%s %s %s", pembeli[i].record[0], pembeli[i].record[1], pembeli[i].record[2]);
    }
    // Menutup file
    fclose(file);
}

// Prosedur untuk memecah pita masukkan user
void PISAHKATA(char str1[])
{
    int flag = 0;
    // Proses pemecahan pita;
    while (flag == 0)
    {
        // Kata masuk ke dalam kategori query
        if ((COMPAREKATA(GETCW(), "ISI") == 1) || (COMPAREKATA(GETCW(), "TAMPIL") == 1))
        {
            COPYKATA(query[a], GETCW());
            a++;
        }
        // Kata masuk ke dalam kategori tabel
        else if (COMPAREKATA(GETCW(), "tumkm") == 1 || COMPAREKATA(GETCW(), "tpembeli") == 1)
        {
            COPYKATA(tabel[b], GETCW());
            b++;
        }
        // Kata masuk ke dalam kategori value
        else
        {
            COPYKATA(record[c], GETCW());
            c++;
        }
        flag = 1;
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

    // Pencarian kata terpanjang
    for (i = 0; i < banyakdata[0]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (longeststr[0][j] < strlen(umkm[i].record[j]))
            {
                longeststr[0][j] = strlen(umkm[i].record[j]);
            }
        }
    }

    longeststr[1][0] = 12;  
    longeststr[1][1] = 12;  
    longeststr[1][2] = 9;

    // Pencarian kata terpanjang
    for (i = 0; i < banyakdata[1]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (longeststr[0][j] < strlen(pembeli[i].record[j]))
            {
                longeststr[0][j] = strlen(pembeli[i].record[j]);
            }
        }
    }

    
}

// Query ISI (memasukkan data ke tabel atau file)
int ISI()
{
    //indeks
    int i, j;

     // Deklarasi File
    FILE *file;
    //jika tabel umkm
    if (COMPAREKATA(tabel[0], "tumkm") == 1)
    {
        file = fopen("tumkm.dat", "w");
        // Proses pemasukkan data
        for (i = 0; i < banyakdata[0]; i++)
        {
            fprintf(file, "%s %s %s\n", umkm[i].record[0], umkm[i].record[1], umkm[i].record[2]);
        }
        fprintf(file, "%s %s %s\n", record[0], record[1], record[2]);
        // Proses ngeprint bagian header tabel
        printf("\n  -------------------------");
        printf("\n[ DATA BERHASIL DITAMBAHKAN ]\n");
        printf("  -------------------------\n");
        //print tabel
        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
        
        printf("| ID UMKM ");
        for (i = 0; i < longeststr[0][0] - 7; i++)
        {
            printf(" ");
        }
        printf("| NAMA USAHA ");
        for (i = 0; i < longeststr[0][1] - 10; i++)
        {
            printf(" ");
        }
        printf("| PEMILIK ");
        for (i = 0; i < longeststr[0][2] - 7; i++)
        {
            printf(" ");
        }
        printf("|\n");
        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
        

        // Proses ngeprint data tabel
        for (j = 0; j < 1; j++)
        {
            printf("| %s ", record[0]);
            for (i = 0; i < longeststr[0][0] - strlen(record[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", record[1]);
            for (i = 0; i < longeststr[0][1] - strlen(record[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", record[2]);
            for (i = 0; i < longeststr[0][2] - strlen(record[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
        printf("\n");
        // Penambahan EOF
        fprintf(file, "#### #### ####\n");
        // Menutup file
        fclose(file);

        return 1;
    }
    //jika tabel pembeli
    else
    {
        file = fopen("tpembeli.dat", "w");
        // Proses pemasukkan data
        for (i = 0; i < banyakdata[1]; i++)
        {
            fprintf(file, "%s %s %s\n", pembeli[i].record[0], pembeli[i].record[1], pembeli[i].record[2]);
        }
        fprintf(file, "%s %s %s\n", record[0], record[1], record[2]);
        // Proses ngeprint bagian header tabel
        printf("\n  -------------------------");
        printf("\n[ DATA BERHASIL DITAMBAHKAN ]\n");
        printf("  -------------------------\n");
        //print tabel
        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
        
        printf("| ID PEMBELI ");
        for (i = 0; i < longeststr[1][0] - 10; i++)
        {
            printf(" ");
        }
        printf("| NAMA PEMBELI ");
        for (i = 0; i < longeststr[1][1] - 12; i++)
        {
            printf(" ");
        }
        printf("| KODE UMKM ");
        for (i = 0; i < longeststr[1][2] - 9; i++)
        {
            printf(" ");
        }
        printf("|\n");
        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
        

        // Proses ngeprint data tabel
        for (j = 0; j < 1; j++)
        {
            printf("| %s ", record[0]);
            for (i = 0; i < longeststr[1][0] - strlen(record[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", record[1]);
            for (i = 0; i < longeststr[1][1] - strlen(record[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", record[2]);
            for (i = 0; i < longeststr[1][2] - strlen(record[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
        printf("\n");
        // Penambahan EOF
        fprintf(file, "#### #### ####\n");
        // Menutup file
        fclose(file);

        return 1;
    }
    
    
}

// Query tampil (Menampilkan tabel)
int TAMPIL()
{
    // Untuk indeks
    int i, j;
    
    //jika tabel tumkm
    if (COMPAREKATA(tabel[0], "tumkm") == 1)
    {
        printf("\n  ---------------");
        printf("\n[ DATA TABEL UMKM ]");
        printf("\n  ---------------\n");

        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
      
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
        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
        

        // Proses ngeprint data tabel
        for (j = 0; j < banyakdata[0]; j++)
        {
            printf("| %s ", umkm[j].record[0]);
            for (i = 0; i < longeststr[0][0] - strlen(umkm[j].record[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", umkm[j].record[1]);
            for (i = 0; i < longeststr[0][1] - strlen(umkm[j].record[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", umkm[j].record[2]);
            for (i = 0; i < longeststr[0][2] - strlen(umkm[j].record[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        GARISTABEL(longeststr[0][0], longeststr[0][1], longeststr[0][2]);
        printf("\n");
        
    }
    //jika tabel pembeli
    else if (COMPAREKATA(tabel[0], "tpembeli") == 1)
    {
        printf("\n  ------------------");
        printf("\n[ DATA TABEL PEMBELI ]");
        printf("\n  ------------------\n");

        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
      
        printf("| ID PEMBELI ");
        for (i = 0; i < longeststr[1][0] - 10; i++)
        {
            printf(" ");
        }
        printf("| NAMA PEMBELI ");
        for (i = 0; i < longeststr[1][1] - 12; i++)
        {
            printf(" ");
        }
        printf("| KODE UMKM ");
        for (i = 0; i < longeststr[1][2] - 9; i++)
        {
            printf(" ");
        }
        printf("|\n");
        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
        

        // Proses ngeprint data tabel
        for (j = 0; j < banyakdata[1]; j++)
        {
            printf("| %s ", pembeli[j].record[0]);
            for (i = 0; i < longeststr[1][0] - strlen(pembeli[j].record[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", pembeli[j].record[1]);
            for (i = 0; i < longeststr[1][1] - strlen(pembeli[j].record[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", pembeli[j].record[2]);
            for (i = 0; i < longeststr[1][2] - strlen(pembeli[j].record[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        GARISTABEL(longeststr[1][0], longeststr[1][1], longeststr[1][2]);
        printf("\n");
        
    }
    return 1;
}
//prosedur membuat garis tabel
void GARISTABEL(int u, int n, int p)
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
//fungsi mengechek eop kata
int CHECKEOP(char input[])
{
    // deklarasi variabel 
    int ex = 0, found = 0;
    // array diisi dengan kata" sesuai eop
    char exit[5][10] = {"jangan",
                        "lupa",
                        "bahagia",
                        "hari",
                        "ini"};
    STARTKATA(input); // memulai mesin kata
    for (int i = 0; i < 5; i++)
    {
        if (COMPAREKATA(GETCW(), exit[i]) == 1) // jika kata pada inputan sama dengan yang ada di array
        {
            ex++; // ex bertambah
        }
        INCKATA(input); // menaikkan kata selanjutnya
    }
    if (ex == 5) // jika katanya sama semua
    {
        found = 1; // found diisi 1
    }
    return found; // mengembalikan nilai found
}
