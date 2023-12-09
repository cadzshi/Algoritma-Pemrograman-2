#include "head.h"
//prosedur tukar
void tukar(int idx1, int idx2) 
{
    temp = mantra[idx1];
    mantra[idx1] = mantra[idx2];
    mantra[idx2] = temp;
}
//prosedur bubblesort
void bs(int n)
{
    int swap = 0;
    do
    {
        for (int i = 0; i < n - 1; i++)
        { 
            if (mantra[i].hasilbagi < mantra[i + 1].hasilbagi)
            { 
                tukar(i, i + 1);
                swap = 1;
            }
        }
    } while (swap  == 1);
}
//prosedur quicksort
void qstengah(int kiri, int kanan)
{ 
    int i, j;
    int pivot;
    i = kiri, j = kanan;
    pivot = mantra[(kanan + kiri) / 2].hasilbagi;
    do
    {
        while ((mantra[i].hasilbagi > pivot) && (i <= j))
        {
            i++;
        }
        while ((mantra[j].hasilbagi < pivot) && (i <= j))
        {
            j--;
        }
    
        if (i < j) 
        {
            tukar(i, j);
            i++; // 
            j--;
        }
    }while (i < j);
   
    if ((kiri < j) && (j < kanan))
    {
        qstengah(kiri, j);
    }
    if ((i < kanan) && (i > kiri))
    {
        qstengah(i, kanan);
    }
}
//prosedur cetak hasil
void printoutput(int n, int totaljam, int totalmenit)
{
    printf("+----+------------------+-------------+-------+\n");
    printf("| No | Nama Mantra      | Magic Power | Waktu |\n");
    printf("+----+------------------+-------------+-------+\n");

    for (int i = 1; i <= n; i++)
    {
        printf("| %d | %s               | %d          | %d    |\n", i, mantra[i].nama, mantra[i].mp, mantra[i].waktu);
        if (i == n)
        {
            printf("+----+------------------+-------------+-------+\n");
        }
        
    }
    
    printf("Anda memerlukan %d jam %d menit untuk menguasai %d mantra diatas\n", totaljam, totalmenit, n);
    

}