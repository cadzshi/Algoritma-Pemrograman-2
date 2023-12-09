#include <stdio.h>

int main()
{
    //penulisan matriks

    /* Cara deklarasi matriks pada bahasa C yaitu :  tipeData namaMatriks[baris][kolom]; */
    // Matriks Statis
    int matriks[5][3];

    int matriks[5][3] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6},
        {5, 6, 7}
    };
    int matriks[5][3] = {1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7};

    // Matriks Dinamis, jumlah baris dan kolom sesuai masukan user
    int n, m; scanf("%d%d", &n, &m);
    int matriks[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matriks[i][j]);
        }  
    }

    return 0;
}