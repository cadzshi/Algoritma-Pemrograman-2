#include <stdio.h>

int main() {
    int m, n;

    printf("Matriks Pusing Kanan Pusing Kiri\n");

    printf("Ukuran Matriks :\n");
    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    int matriks[m][n];
    int transpose[n][m];
    int mirror[m][n];
    int mirrorT[n][m];

    int baris;
    int kolom;
    int arah;
    int jumlah;

    printf("Isi Matriks:\n");
    for (baris = 0; baris < m; baris++)
    {
        for (kolom = 0; kolom < n; kolom++)
        {
            printf("masukkan angka: ");
            scanf("%d", &matriks[baris][kolom]);
            //printf("\n");
        }
    }

    printf("\nMatriks Masukan:\n");
    for (baris = 0; baris < m; baris++)
    {
        for (kolom = 0; kolom < n; kolom++)
        {
            printf("%d ", matriks[baris][kolom]);
        }
        printf("\n");
    }

    printf("Ketik '1' untuk kanan dan '0' untuk kiri:\n");
    scanf("%d", &arah);

    if (arah != 1 && arah != 0)
    {
        printf("nggak ngerti :(\n");
        return 0;
    } 
    
    printf("Berapa putaran?\n");
    scanf("%d", &jumlah);
    
    jumlah = jumlah%4;

    if (arah == 1)
    {
        switch (jumlah)
        {
            case 0:
                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        printf("%d ", matriks[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 1:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        transpose[kolom][baris] = matriks[baris][kolom];
                    }
                }

                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        mirrorT[baris][kolom] = transpose[baris][(m-1)-kolom];
                    }
                }

                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        printf("%d ", mirrorT[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 2:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        mirror[baris][kolom] = matriks[(m-1)-baris][(n-1)-kolom];
                    }
                }

                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        printf("%d ", mirror[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 3:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        transpose[kolom][baris] = matriks[baris][kolom];
                    }
                }

                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        mirrorT[baris][kolom] = transpose[(n-1)-baris][kolom];
                    }
                }

                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        printf("%d ", mirrorT[baris][kolom]);
                    }
                    printf("\n");
                }

            break;
        
            default:
            break;
        }
    }
    else
    {
        switch (jumlah)
        {
            case 0:
                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        printf("%d ", matriks[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 1:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        transpose[kolom][baris] = matriks[baris][kolom];
                    }
                }

                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        mirrorT[baris][kolom] = transpose[(n-1)-baris][kolom];
                    }
                }

                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        printf("%d ", mirrorT[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 2:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        mirror[baris][kolom] = matriks[(m-1)-baris][(n-1)-kolom];
                    }
                }

                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        printf("%d ", mirror[baris][kolom]);
                    }
                    printf("\n");
                }
            break;

            case 3:
                for (baris = 0; baris < m; baris++)
                {
                    for (kolom = 0; kolom < n; kolom++)
                    {
                        transpose[kolom][baris] = matriks[baris][kolom];
                    }
                }

                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        mirrorT[baris][kolom] = transpose[baris][(m-1)-kolom];
                    }
                }

                printf("\nHasil Perubahan:\n");
                for (baris = 0; baris < n; baris++)
                {
                    for (kolom = 0; kolom < m; kolom++)
                    {
                        printf("%d ", mirrorT[baris][kolom]);
                    }
                    printf("\n");
                }

            break;
        
            default:
            break;
        }
    }
    
    return 0;
}