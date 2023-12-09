#include <stdio.h>
#include <string.h>


// struct yang mendefinisikan sebauh koordinat lokasi
typedef struct
{
    char namaLokasi[50];
    float latitude;
    float longitude;
} koordinatLokasi;


// Utility: menulis data dari parameter yang diberikan ke file
// Parameters: n -> jumlah data, source[] -> array of data yang ingin ditulis, filename[] -> nama filenya
// Return: None
void writeToFile(int n, koordinatLokasi source[], char filename[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write


    // tulis data ke file
    for (int i = 0; i < n; i++)
    {
        // tulis 3 kolom lalu beri newline
        fprintf(fTemp, "%s %f %f\n", source[i].namaLokasi, source[i].latitude,
                source[i].longitude);
    }


    // berikan EOF di akhir file
    fprintf(fTemp, "%s %f %f\n", "####", -9999.0, -9999.0);


    // "tutup file"
    fclose(fTemp);
}


int main()
{
    int n;


    // scan jumlah data yang ingin dimasukkan
    scanf("%d", &n);


    // buat array of lokasi sebanyak n
    koordinatLokasi lokasi[n];


    // scan masukan user
    for (int i = 0; i < n; i++)
    {
        printf("Lokasi ke-%d\n", i + 1);
        printf("    Nama Lokasi: ");
        scanf("%s", lokasi[i].namaLokasi); // nama lokasi


        printf("    latitude: ");
        scanf("%f", &lokasi[i].latitude); // latitude


        printf("    longitude: ");
        scanf("%f", &lokasi[i].longitude); // longitude
    }


    // panggil prosedur writeToFile untuk menulis data yang tersimpan di variabel lokasi
    writeToFile(n, lokasi, "TestFile.dat");


    return 0;
}
