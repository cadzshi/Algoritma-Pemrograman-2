#include "head.h"

void scandata (data nama_matriks[baris][kolom])
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf("%d %s %s", &nama_matriks[i][j].nama_variabel1, &nama_matriks[i][j].nama_variabel2, &nama_matriks[i][j].nama_variabel3);
        }
    }
}

void printdata (data nama_matriks[baris][kolom])
{
    for (int i = 0; i < baris; i++)
    {
        printf("Baris ke-%d:\n", i + 1);
        for (int j = 0; j < kolom; j++)
        {
            printf("Variabel 1 : %d\n", nama_matriks[i][j].nama_variabel1);
            printf("Variabel 2 : %s\n", nama_matriks[i][j].nama_variabel2);
            printf("Variabel 3 : %s\n", nama_matriks[i][j].nama_variabel3);
            printf("---------------------------------\n");
        }
        printf("=================================\n");
    }
}