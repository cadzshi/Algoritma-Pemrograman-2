#include <stdio.h>
#include <string.h>

//ex 1
typedef struct 
{
    char nama[100];
    char grade;
    int nilai;
}siswa;

int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);

    siswa matriks[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%s", matriks[i][j].nama);
            scanf(" %c", &matriks[i][j].grade);
            scanf("%d", &matriks[i][j].nilai);
        }
    }
    printf("=========================\n");
    
    for (i = 0; i < n; i++)
    {
        printf("Baris %dl\n", i+1);
        for (j = 0; j < m; j++)
        {
            printf("Nama Siswa : %s\n", matriks[i][j].nama);
            printf("Grade Nilai : %c\n", matriks[i][j].grade);
            printf("Nilai : %d\n", matriks[i][j].nilai);
            printf("------------------------\n");
        }
        printf("=========================\n");
    }
    return 0;
}