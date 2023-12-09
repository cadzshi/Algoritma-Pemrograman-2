#include "head.h"

int main()
{
    //scan ukuran matrix
    scanf("%d %d", &n, &m);

    data awal[n][m];    //matrix untuk posisi awal
    data akhir[n][m];   //matrix untuk posisi akhir
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //scan matrix
            scanf("%s", &akhir[i][j].nama); //nama
            scanf("%d", &akhir[i][j].ipa);  //nilai ipa
            scanf("%d", &akhir[i][j].mtk);  //nilai mtk
            scanf("%d", &akhir[i][j].eng);  //nilai eng
            awal[i][j] = akhir[i][j];       //salin matrix akhir ke matrix awal
        }
    }

    char kiri[50], kanan[50];   //variabel untuk siswa yang akan ditukar
    data *namakiri, *namakanan; //pointer siswa yang akan ditukar
    do
    {
        //scan nama siswa
        scanf("%s", &kiri);
        if (strcmp(kiri, "Selesai") == 0)   //kalo bukan "Selesai" lanjut scan 
        {
            break;  //kalo iya, maka break
        }
        scanf("%s", &kanan);
        //proses buat mencari nama siswa
        namakiri = find_str(kiri, akhir);
        namakanan = find_str(kanan, akhir);
        //proses buat nuker posisi sesuai syarat
        if (average((*namakiri).ipa, (*namakiri).mtk, (*namakiri).eng) < average((*namakanan).ipa, (*namakanan).mtk, (*namakanan).eng))
        {
            swap(namakiri, namakanan);
        }
    } while (0 == 0);

    //print outputnya
    printf("Posisi Awal:\n");
    printhasil(awal);

    printf("\nPosisi Akhir:\n");
    printhasil(akhir);
    return 0;
}

//aq pusinkkkkkk maz
