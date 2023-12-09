#include<stdio.h>
/*
int main()
{
    int matriks[3][2];
    int b, k;

    for(b = 0; b < 3; b++)
    {
        for (k = 0; k < 2; k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks[b][k]);
            printf("\n");
        }   
    }
    return 0;
}
*/
/*
int main ()
{
    int matriks[4][6];
    int b, k;

    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks[b][k]);
            printf("\n");
        }
    }
    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            printf("masukkan angka:\n");
        }
        printf("\n");
    }

    return 0;
}
*/
/*
int main()
{
    int matriks1[4][6];
    int matriks2[4][6];
    int b, k;

    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks1[b][k]);
            printf("\n");
        }
    }
    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            matriks2[b][k] = matriks1[b][k];
        }
    }

    return 0;
}
*/

//belom pertambahan/pengurangan
/*
int main()
{
    int matriks1[4][6];
    int matriks2[4][6];
    int matriks3[4][6];
    int b, k;

    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks1[b][k]);
            printf("\n");
        }
    }
    for(b = 0;b < 4;b++)
    {
        for(k = 0;k < 6;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks2[b][k]);
            printf("\n");
        }
    }

    return 0;
}
*/

//perkalian 
int main()
{
    int matriks1[3][2];
    int matriks2[2][3];
    int matriks3[3][3];
    int b, k, jk;

    //mengisi matriks pertama
    for(b = 0;b < 3;b++)
    {
        for (k = 0;k < 2;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks1[b][k]);
            printf("\n");
        }   
    }
    //mengisi matriks kedua
    for(b = 0;b < 2;b++)
    {
        for (k = 0;k < 3;k++)
        {
            printf("masukkan angka:\n");
            scanf("%d", &matriks2[b][k]);
            printf("\n");
        }
        
    }

    return 0;
}