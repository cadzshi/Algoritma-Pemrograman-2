#include "header.h"

void insertion(int n, char nama[][50])
{
    char temp[50];
    for (int i = 0; i < n; i++)
    {
        strcpy(temp, nama[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(nama[j], temp) > 0)
        {
            strcpy(nama[j + 1], nama[j]);
            j--;
        }
        strcpy(nama[j + 1], temp);
    }
}

void selection(int n, char nama[][50])
{
    char temp[50];
    for (int i = 0; i < (n - 1); i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(nama[j], nama[maxIndex]) > 0)
            {
                maxIndex = j;
            }
        }
        strcpy(temp, nama[i]);
        strcpy(nama[i], nama[maxIndex]);
        strcpy(nama[maxIndex], temp);
    }
}

void printsorting(int n, char nama[][50], char metode[50])
{
     if (strcmp(metode, "insertion") == 0)
    {
        insertion(n, nama);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", &nama[i]);
        }
    }
    else if (strcmp(metode, "selection") == 0)
    {
        selection(n, nama);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", &nama[i]);
        }
    }
}