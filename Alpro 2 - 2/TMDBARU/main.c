#include "head.h"

int main()
{
    char query[501], fungsi[2][20];
    int flag = 0, tanda = 0;
    int index;
    /*
        (1) query = pita masukkan user
        (2) fungsi = menampung query masukkan user
        (3) flag = sebagai tanda
        (4) tanda = sebagai tanda
        (5) index = buat index dalam fungsi for/while
    */

    printf("Selamat Datang di DBMS Rosad\nVersi 1.0\n\n");
    printf("dbms rosad > ");

    // Meminta masukkan pita dari user
    scanf(" %500[^\n]s", &query);

    // Memulai pembacaan pita
    start(query);

    //Cek kondisi apakah masukkan user adalah "exit;"
    if ((COMPAREKATA(getcw(), "exit") == 1) && (query[strlen(query)] == ';'))
    {
        flag = 1;
    }

    // While jika masukkan user bukan "exit;"
    while (flag != 1)
    {
        // Mereset char fungsi mejadi string kosong
        for (index = 0; index < 2; index++)
        {
            fungsi[index][0] = '\0';
        }
        index = 0;

        // While jika querynya belum mencapai eop
        while (eop(query) == 0)
        {
            // Pemasukkan query kepada variabel fungsi
            if ((COMPAREKATA(getcw(), "TAMPIL") == 1) || (COMPAREKATA(getcw(), "ISI") == 1) || (COMPAREKATA(getcw(), "UBAH") == 1) || (COMPAREKATA(getcw(), "HAPUS") == 1))
            {
                COPYKATA(fungsi[index], getcw());
                index++;
            }
            // Pemecahan pita
            explode(query);
            // Lanjut membaca kata berikutnya
            inc(query);
        }
        // Pemecahan pita
        explode(query);
        // Mengambil record data dari tabel
        ambildata();
        // Mencari kata terpanjang tiap tabel
        FINDLONGEST();
        // Proses pengecekkan error (flag = 1 -> ada error | flag = 0 -> gak ada error)
        
        index = 0;
        tanda = 0;
        // While jika tanda = 0 (belum ada query yang dijalankan) dan index < 2 (maksimal query adalah 2)
        while (tanda == 0 && index < 2)
        {
            // Menjalankan query ISI
            if (COMPAREKATA(fungsi[index], "ISI") == 1)
            {
                tanda = ISI();
                printf("isi\n");
            }
            // Menjalankan query TAMPIL
            else if (COMPAREKATA(fungsi[index], "TAMPIL") == 1)
            {
                tanda = TAMPIL();
            }
            // else if (COMPAREKATA(fungsi[index], "UBAH") == 1)
            // {
            //     tanda = UBAH();
            // }
            index++;
        }
        

        printf("\ndbms rosad > ");
        // Meminta masukkan user kembali
        scanf(" %500[^\n]s", &query);
        // Mulai membaca kata
        start(query);
        //Cek kondisi apakah masukkan user adalah "exit;"
        if ((COMPAREKATA(getcw(), "exit") == 1) && (query[strlen(query)] == ';'))
        {
            flag = 1;
        }
    }

    return 0;
}
