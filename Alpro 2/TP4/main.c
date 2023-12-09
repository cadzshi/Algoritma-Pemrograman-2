//library
#include "head.h"
//deklarasi fungsi
int main()
{
    //variabel jumlah data
    int n;
    scanf("%d", &n); //scan

    //variabel nama dan umur
    char namaAw[n][50];     //nama awal untuk proses penjumlahan nanti
    char namaAk[n][50];     //nama akhir untuk proses sorting
    int umurAw[n];          //umur awal juga untuk proses penjumlahan
    int umurAk[n];          //umur akhir untuk proses sorting

    //scan nama dan umur sesuai n
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", &namaAk[i], &umurAk[i]);
        namaAw[i][50] = namaAk[i][50];  //masukkan nama akhir ke nama awal
        umurAw[i] = umurAk[i];          //umur jg sama
    }
    
    //variabel metode sorting
    char metode[10];
    scanf("%s", &metode);   //scan

    //ya panggil prosedur
    hasil(n, namaAk, umurAk, namaAw, umurAw, metode);
    
    return 0;
}