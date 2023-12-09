#include "head.h"

int main()
{
    //deklarasi variabel
    char input[501], fungsi[2][20]; //pita masukan, menampung query
    int flag = 0, tanda = 0;        //penanda
    int index;                      //indeks
   

    printf("Selamat Datang di DBMS Rosad\n");
    printf("Versi 1.0\n\n");
    
    // While jika eop != 1
    while (flag != 1)
    {
        printf("[dbms rosad]> ");
        // Meminta masukkan user
        scanf(" %500[^\n]s", &input);
        //Cek kondisi apakah masukkan user adalah sesuai eop
        if (CHECKEOP(input) == 1)
        {
            printf("\nTHANK YOU!\nJANGAN LUPA TERSENYUM :)\n");
            exit(EXIT_SUCCESS);
            flag = 1;
        }
        //memulai mesin kata
        STARTKATA(input);
        // Mereset char fungsi mejadi string kosong
        for (index = 0; index < 2; index++)
        {
            fungsi[index][0] = '\0';
        }
        index = 0;

        // While jika inputnya belum mencapai eop
        while (EOPKATA(input) == 0)
        {
            // Pemasukkan input kepada variabel fungsi
            if ((COMPAREKATA(GETCW(), "TAMPIL") == 1) || (COMPAREKATA(GETCW(), "ISI") == 1))
            {
                COPYKATA(fungsi[index], GETCW());   //copy cw ke fungsi
                index++;                            //indeks bertambah
            }
            // Pemecahan pita
            PISAHKATA(input);
            // Lanjut membaca kata berikutnya
            INCKATA(input);
        }
        // Pemecahan pita
        PISAHKATA(input);
        // Mengambil record data dari tabel
        AMBILDATA();
        // Mencari kata terpanjang tiap tabel
        FINDLONGEST();
        
        tanda = 0;
        index = 0;
        // While jika tanda = 0 (belum ada input yang dijalankan) dan query kurang dari 1
        while (tanda == 0 && index < 1)
        {
            // Menjalankan input ISI
            if (COMPAREKATA(fungsi[index], "ISI") == 1)
            {
                tanda = ISI();
            }
            // Menjalankan input TAMPIL
            else if (COMPAREKATA(fungsi[index], "TAMPIL") == 1)
            {
                tanda = TAMPIL();
            } 
            index++;
        }
    }
    return 0;
}

