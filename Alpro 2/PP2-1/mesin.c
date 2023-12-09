#include "head.h"

void scanwarna (data warna[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%s", warna[i][j].nama);
            scanf("%d", &warna[i][j].red);
            scanf("%d", &warna[i][j].green);
            scanf("%d", &warna[i][j].blue);
        }
    }
    scanf("%s", dicari);
}

void printwarna (data warna[n][m])
{
    for (int i = 0; i < n; i++)
    {
        int ketemu = 0, tidakketemu = 0;
        pembatas();
        printf("Baris %d:\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            if (strcmp(dicari, warna[i][j].nama) == 0)
            {
                tidakketemu = 1;
                printf("Detail Warna Merah : %d\n", warna[i][j].red);
                printf("Detail Warna Hijau : %d\n", warna[i][j].green);
                printf("Detail Warna Biru : %d\n", warna[i][j].blue);
                pembatas2();
            }
            else
            {
                ketemu = 1;
            }
        }
        if (ketemu == 1 && tidakketemu == 0)
        {
            printf("Tidak ada warna %s.\n", dicari);
        }
    }
}

void pembatas()
{
    printf("=======================\n");
}

void pembatas2()
{
    printf("-----------------------\n");
}