#include <stdio.h>
#include <string.h>


// struct untuk mendefinisikan seorang Mahasiswa.
// *fun facts: struct di sini memiliki kemiripan dengan paradigma OOP
// seperti sebuah "kelas", disebut juga sebagai "kelas abal abal" -pak Rasim
typedef struct
{
    char nim[10];
    char nama[100];
    char jurusan[100];
    float ipk;
} dataMahasiswa;


// deklarasi
void readFromFile(int *n, dataMahasiswa source[], char filename[]);
void writeToFile(int n, dataMahasiswa source[], char filename[]);


int main()
{
    int n = 0;
    dataMahasiswa mahasiswa[100]; // penampung data mahasiswa max 100


    // baca dari file lalu simpan datanya ke variabel mahasiswa
    readFromFile(&n, mahasiswa, "listMahasiswa.dat");


    // karena n adalah jumlah data yang dibaca, maka bisa digunakan untuk proses "append"
    // dengan cara melanjutkan penambahan data ke variabel mahasiswa lewat scan user
    printf("Tambah Mahasiswa:\n");
    scanf("%s %s %s %f", // scan data yang ingin ditambahakan
          mahasiswa[n].nim,
          mahasiswa[n].nama,
          mahasiswa[n].jurusan,
          &mahasiswa[n].ipk);
    while (strcmp(mahasiswa[n].nim, "####") != 0) // selama data yang discan bukan EOF
    {
        n++;
        scanf("%s %s %s %f", // scan data
              mahasiswa[n].nim,
              mahasiswa[n].nama,
              mahasiswa[n].jurusan,
              &mahasiswa[n].ipk);
    }


    //tulis data yang ada di variabel mahasiswa ke file
    // sebenarnya ini adalah prosess rewrite
    // yaitu mengahpus isi semua file lalu di tulis dengan data yang baru
    writeToFile(n, mahasiswa, "listMahasiswa.dat");


    return 0;
}


// Utility: membaca data dari file lalu simpan ke paramater
// Parameters: n -> jumlah data, source[] -> array of data yang ingin dijadikan penampung, filename[] -> nama filenya
// Return: None
void readFromFile(int *n, dataMahasiswa source[], char filename[])
{
    FILE *fTemp;
    fTemp = fopen(filename, "r"); // buka file dengan mode read


    int returnVal = fscanf(fTemp, "%s %s %s %f", // scan 4 data pertama (baris 1)
                           source[*n].nim,
                           source[*n].nama,
                           source[*n].jurusan,
                           &source[*n].ipk);


    // cek apakah scan tadi kolom nimnya merukan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(source[*n].nim, "####") == 0 || returnVal == EOF)
    {
        // jika, ya maka file kosong
        printf("File Kosong\n");
    }
    else
    {
        // jika tidak maka bisa scan kembali selama kolom nim bukan EOF
        while (strcmp(source[*n].nim, "####") != 0)
        {
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s %f", // scan 4 data selanjutnya (baris 2 dan seterusnya)
                   source[*n].nim,
                   source[*n].nama,
                   source[*n].jurusan,
                   &source[*n].ipk);
        }


        // tampilkan data setelah selesai baca
        printf("Data Mahasiswa(%d):\n", *n);
        for (int i = 0; i < *n; i++)
        {
            printf("%s %s %s %.2f\n",
                   source[i].nim,
                   source[i].nama,
                   source[i].jurusan,
                   source[i].ipk);
        }
    }


    // "tutup file"
    fclose(fTemp);
}


// Utility: menulis data dari parameter yang diberikan ke file
// Parameters: n -> jumlah data, source[] -> array of data yang ingin ditulis, filename[] -> nama filenya
// Return: None
void writeToFile(int n, dataMahasiswa source[], char filename[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++)
    {
        fprintf(fTemp, "%s %s %s %.2f\n", // tulis 4 kolom lalu beri newline
                source[i].nim,
                source[i].nama,
                source[i].jurusan,
                source[i].ipk);
    }


    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s %s %.1f\n", "####", "####", "####", -9999.0);


    // "tutup file"
    fclose(fTemp);
}
