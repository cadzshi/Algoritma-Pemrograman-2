#include "head.h"
#include <stdio.h>

int main()
{
    // deklarasi variabel jumlah perintah dan pita
    int i, n;
    char tape[128];
    student data[50];


    // meminta masukan
    printf("Masukkan jumlah perintah : ");
    scanf("%d", &n);


    // memulai perulangan untuk menjalankan setiap perintah
    for (i = 0; i < n; i++)
    {
        scanf(" %127[^\n]s", &tape); // ada spasi sebelum simbol %
      	modify_data(tape, &data[i]); // lengkapi mesinnya
    }


    for (i = 0; i < n; i++)
    {
        printf("%d. %s %s %s\n", (i + 1), data[i].nim, data[i].nama, data[i].nilai);
    }


    return 0;
}
