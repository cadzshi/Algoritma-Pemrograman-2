//library
#include "head.h"

//prosedur sorting sesuai dengan soal
void INA (int n, char namaAk[][50])
{
    char temp[50];
    for (int i = 0; i < n; i++)
    {
        strcpy(temp, namaAk[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(namaAk[j], temp) > 0)
        {
            strcpy(namaAk[j + 1], namaAk[j]);
            j--;
        }
        strcpy(namaAk[j + 1], temp);
    }
}

void IND (int n, char namaAk[][50])
{
    char temp[50];
    for (int i = 0; i < n; i++)
    {
        strcpy(temp, namaAk[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(namaAk[j], temp) < 0)
        {
            strcpy(namaAk[j + 1], namaAk[j]);
            j--;
        }
        strcpy(namaAk[j + 1], temp);
    }
}

void IUA (int n, int umurAk[])
{
    for (int i = 0; i < 8; i++)
    {
        int key = umurAk[i];
        int j = i - 1;

        while (j >= 0 && key < umurAk[j])
        {
            umurAk[j + 1] = umurAk[j];
            j--;
        }
        umurAk[j + 1] = key;
    }
}

void IUD (int n, int umurAk[])
{
    for (int i = 0; i < 8; i++)
    {
        int key = umurAk[i];
        int j = i - 1;

        while (j >= 0 && key > umurAk[j])
        {
            umurAk[j + 1] = umurAk[j];
            j--;
        }
        umurAk[j + 1] = key;
    }
}

void SNA (int n, char namaAk[][50])
{
    char temp[50];
    for (int i = 0; i < n-1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (strcmp(namaAk[j], namaAk[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            strcpy(temp, namaAk[i]);
            strcpy(namaAk[i], namaAk[minIndex]);
            strcpy(namaAk[minIndex], temp);
        }
    }
}

void SND (int n, char namaAk[][50])
{
    char temp[50];
    for (int i = 0; i < (n - 1); i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(namaAk[j], namaAk[maxIndex]) > 0)
            {
                maxIndex = j;
            }
        }
        strcpy(temp, namaAk[i]);
        strcpy(namaAk[i], namaAk[maxIndex]);
        strcpy(namaAk[maxIndex], temp);
    }
}

void SUA (int n, int umurAk[])
{
    int minIndex, temp;
    for (int i = 0; i < (n - 1); i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (umurAk[minIndex] > umurAk[j])
            {
                minIndex = j;
            }
        }
        temp = umurAk[i];
        umurAk[i] = umurAk[minIndex];
        umurAk[minIndex] = temp;
    }
}

void SUD (int n, int umurAk[])
{
    int minIndex, temp;
    for (int i = 0; i < (n - 1); i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (umurAk[minIndex] < umurAk[j])
            {
                minIndex = j;
            }
        }
        temp = umurAk[i];
        umurAk[i] = umurAk[minIndex];
        umurAk[minIndex] = temp;
    }
}

//prosedur pilihan asramaa
void pilihanAsrama(char namaAk[][50], int umurAk[], char namaAw[][50], int umurAw[])
{
    if ((namaAk[0][50] + namaAw[0][50]) % 2 == 0 && (umurAk[0] + umurAw[0]) % 2 == 0)
    {
        printf("Selamat, Anda masuk ke asrama Gryffindor!\n");
    }
    else if ((namaAk[0][50] + namaAw[0][50]) % 2 == 0 && (umurAk[0] + umurAw[0]) % 1 == 0)
    {
        printf("Selamat, Anda masuk ke asrama Hufflepuff!\n");
    }
    else if ((namaAk[0][50] + namaAw[0][50]) % 1 == 0 && (umurAk[0] + umurAw[0]) % 1 == 0)
    {
        printf("Selamat, Anda masuk ke asrama Ravenclaw!\n");
    }
    else if ((namaAk[0][50] + namaAw[0][50]) % 1 == 0 && (umurAk[0] + umurAw[0]) % 2 == 0)
    {
        printf("Selamat, Anda masuk ke asrama Slytherin!\n");
    }
}
//ini prosedur print doang
void printsort (int n, char namaAk[][50], int umurAk[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", namaAk[i], umurAk[i]); 
    }
}
//nah ini hasil akhir
void hasil (int n, char namaAk[][50], int umurAk[], char namaAw[][50], int umurAw[], char metode[10])
{
    printf("Hasil setelah diurutkan :\n");
    if (strcmp(metode, "INA") == 0)
    {
        INA(n, namaAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "IND") == 0)
    {
        IND(n, namaAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "IUA") == 0)
    {
        IUA(n, umurAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "IUD") == 0)
    {
        IUD(n, umurAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "SNA") == 0)
    {
        SNA(n, namaAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "SND") == 0)
    {
        SND(n, namaAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "SUA") == 0)
    {
        SUA(n, umurAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
    else if (strcmp(metode, "SUD") == 0)
    {
        SUD(n, umurAk);
        printsort(n, namaAk, umurAk);
        pilihanAsrama(namaAk, umurAk, namaAw, umurAw);
    }
}

