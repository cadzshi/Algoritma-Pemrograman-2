#include "head.h"
//prosedur scan
void scanmatriks(int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }
}

//prosedur print matrix awal
void printmatriksawal(int m, int n)
{
    printf("Matriks Awal :\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
}
/*
void solve(int m, int n)
{
    int jumlah = (m + n) % 4;
    if ((m + n) % 2 == 0)
    {
        switch (jumlah)
        {
            case 0;

        }
    }
    
}
*/