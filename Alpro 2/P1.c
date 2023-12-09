#include <stdio.h>

/*
int main()
{
    //mengisi matriks
    int matriks[3][2];
    int baris, kolom;

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 2; kolom++)
        {
            printf("Masukkan angka:\n");
            scanf("%d", &matriks[baris][kolom]);
            printf("\n");
        }
    }
}
*/
/*
int main()
{
    //menampilkan matriks
    int matriks[3][3];
    int baris, kolom;

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks[baris][kolom]);
        }
    }
    
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            printf("%d ", matriks[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}
*/
/*
int main()
{
    //menyalin matriks
    int matriks1[3][3];
    int matriks2[3][3];
    int baris, kolom;

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks1[baris][kolom]);
        }
    }

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            matriks2[3][3] = matriks1[3][3];
        }
    }
    return 0;
}
*/
/*
int main()
{
    //penjumlahan matriks
    int matriks1[3][3];
    int matriks2[3][3];
    int matriks3[3][3];
    int baris, kolom;

    printf("Matriks 1\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks1[baris][kolom]);
        }
    }
    printf("Matriks 2\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks2[baris][kolom]);
        }
    }

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            matriks3[baris][kolom] = matriks1[baris][kolom] + matriks2[baris][kolom];
        }
    }
    printf("Hasil Penjumlahan[\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            printf("%d ", matriks3[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}
*/
/*
int main()
{
    //pengurangan matriks
    int matriks1[3][3];
    int matriks2[3][3];
    int matriks3[3][3];
    int baris, kolom;

    printf("Matriks 1\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks1[baris][kolom]);
        }
    }
    printf("Matriks 2\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks2[baris][kolom]);
        }
    }

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            matriks3[baris][kolom] = matriks1[baris][kolom] - matriks2[baris][kolom];
        }
    }
    printf("Hasil Pengurangan\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            printf("%d ", matriks3[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}
*/

int main()
{
    //perkalian matriks
    int matriks1[3][3];
    int matriks2[3][3];
    int matriks3[3][3];
    int baris, kolom, jumlahkali;

    printf("Matriks 1\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks1[baris][kolom]);
        }
    }
    printf("Matriks 2\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            scanf("%d", &matriks2[baris][kolom]);
        }
    }

    printf("Hasil Perkalian\n");
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            matriks3[baris][kolom] = 0;
            for (jumlahkali = 0; jumlahkali < 2; jumlahkali++)
            {
                matriks3[baris][kolom] += (matriks1[baris][jumlahkali] * matriks2[jumlahkali][kolom]);
            }
            
        }
        
    }
    
    return 0;
}