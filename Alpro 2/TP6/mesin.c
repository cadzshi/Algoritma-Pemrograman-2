#include "head.h"

void scandata(data murid[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s", &murid[i].nama, &murid[i].power, &murid[i].spell);
    }
}

void swap(data *a, data *b)
{
    data temp;
    temp *a;
    *a = *b;
    *b = temp;
}

void sorting(data murid[], int n, char tipe[10])
{
    if (strcmp(tipe, "Spell") == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int idx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (murid[j].spell < murid[idx].spell) 
                {
                    idx = j;
                }
            }
            swap(&murid[i], &murid[idx]);
        }
    }
    else if (strcmp(tipe, "Power") == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int idx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (murid[j].power > murid[idx].power)
                {
                    idx = j;
                } 
            }
            swap(&murid[i], &murid[idx]);
        }
    }
}


void merge(data murid1[], int n1, data murid2[], int n2, data murid3[], char tipe[10])
{
    int i = 0, i1 = 0, i2 = 0;
    if (strcmp(tipe, "Spell") == 0)
    {
        while (i1 < n1 && i2 < n2)
        {
            if (murid1[i1].spell <= murid2[i2].spell)
            {
                murid3[i++] = murid1[i1++];  
            }
            else 
            {
                murid3[i++] = murid2[i2++];
            }
        }
    }
    else if (strcmp(tipe, "Power") == 0)
    {
       while (i1 < n1 && i2 < n2)
        {
            if (murid1[i1].power >= murid2[i2].power)
            {
                murid3[i++] = murid1[i1++];  
            }
            else 
            {
                murid3[i++] = murid2[i2++];
            }
        }
    }
    while (i1 < n1) 
    {
        murid3[i++] = murid1[i1++];
    }
    while (i2 < n2) 
    {
        murid3[i++] = murid2[i2++];
    }
}

void printdata(data murid[], int n)
{
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n\n");
    printf("= A L L   W I Z A R D S =\n");
    
}