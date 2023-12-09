/*
Saya Farhan Muzhaffar Tiras Putra NIM 2105879
mengerjakan Tugas Masa Depan dalam mata kuliah Algoritma dan Pemograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin.
*/

// menggunakan library yang telah dibuat
#include "mesinkata.h"

int main()
{
    // deklarasi indikator untuk berhenti
    int berhenti = 0;

    // menampilkan pesan welcome
    printf("Welcome to Farhan's DBMS\n");
    printf("Versi 1.0\n\n");

    // looping untuk programnya
    while (berhenti != 1)
    {
        // deklarasi variabel
        int i, n;
        m = 0;
        t = 0;

        // deklarasi variabel betipe data bungkusan yang sudah dibuat
        riders Rdata;
        motors RdataMotor;

        printf("Farhan's DBMS> ");
        // deklarasi string untuk input
        char input[256];
        scanf(" %255[^\n]s", &input); // meminta minput untuk query
        // memanggil prosedur untuk menghitung query yang digunakan
        COUNTQUERY(input);
        // memanggil prosedur untuk mendapatkan data inputan
        GETDATA(input);
        // deklarasi variabel cek untuk digunakan menentukan tabel yang mana dari inputan

        // memanggil prosedur untuk menentukan apakah inputan sekarang adalah eop atau query untuk mengakhiri program
        if (CHECKEOP(input) == 1)
        {
            printf("\nTHANK YOU!\nKEEP ON RACING!!\n\n");
            system("pause");    // tampilan akan dipause
            exit(EXIT_SUCCESS); // akan mengakhiri program
            berhenti = 1;       // berhenti berubah menjadi 1
        }

        // memulai mesin kata
        STARTKATA(input);
        // jika tablenya adalah table riders
        if (CHECKTABLE(input) == 0)
        {
            int query = CHECKQUERY(input, Rdata); // mengecek query yang harus digunakan
            switch (query)                        // switch untuk menentukan query yang dijalankan
            {
            case 1:
                QUERYINUSE(query, input); // menentukan tampilkan yang akan dikeluarkan
                INCKATA(input);           // menaikkan kata selanjutnya
                ENTRI(input, Rdata);      // menjalankan query ENTRI
                system("pause");          // tampilan akan dipause
                break;                    // mengakhiri switch
            case 2:
                QUERYINUSE(query, input); // menentukan tampilkan yang akan dikeluarkan
                INCKATA(input);           // menaikkan kata selanjutnya
                UBAH(input, Rdata);       // menjalankan query UBAH
                system("pause");          // tampilan akan dipause
                break;                    // mengakhiri switch
            case 3:
                QUERYINUSE(query, input); // menentukan tampilkan yang akan dikeluarkan
                INCKATA(input);           // menaikkan kata selanjutnya
                HAPUS(input, Rdata);      // menjalankan query HAPUS
                system("pause");          // tampilan akan dipause
                break;                    // mengakhiri switch
            case 4:
                QUERYINUSE(query, input); // menentukan tampilkan yang akan dikeluarkan
                INCKATA(input);           // menaikkan kata selanjutnya
                TAMPIL(input, Rdata);     // menjalankan query TAMPIL
                system("pause");          // tampilan akan dipause
                break;                    // mengakhiri switch

            default:
                break; // mengakhiri switch
            }
        }
        else if (CHECKTABLE(input) == 1) // jika tablenya adalah table motors
        {
            int query = CHECKQUERYMOTOR(input, RdataMotor);
            switch (query)
            {
            case 1:
                QUERYINUSE(query, input); // menentukan tampilkan yang akan dikeluarkan

                ENTRIMOTOR(input, RdataMotor); // menjalankan query ENTRI untuk motor
                system("pause");               // tampilan akan dipause
                break;                         // mengakhiri switch
            case 2:
                QUERYINUSE(query, input);     // menentukan tampilkan yang akan dikeluarkan
                UBAHMOTOR(input, RdataMotor); // menjalankan query UBAH untuk motor
                system("pause");              // tampilan akan dipause
                break;                        // mengakhiri switch
            case 3:
                QUERYINUSE(query, input);      // menentukan tampilkan yang akan dikeluarkan
                HAPUSMOTOR(input, RdataMotor); // menjalankan query HAPUS untuk motor
                system("pause");               // tampilan akan dipause
                break;                         // mengakhiri switch
            case 4:
                QUERYINUSE(query, input);       // menentukan tampilkan yang akan dikeluarkan
                TAMPILMOTOR(input, RdataMotor); // menjalankan query TAMPIL untuk motor
                system("pause");                // tampilan akan dipause
                break;                          // mengakhiri switch

            default:
                break; // mengakhiri switch
            }
        }
        else // jika tablenya invalid
        {
            printf("\nPLEASE INPUT A VALID TABLE\n\n");
        }
        input[0] = '\0'; // mengkosongkan input
    }
    return 0; // mengakhiri program
}