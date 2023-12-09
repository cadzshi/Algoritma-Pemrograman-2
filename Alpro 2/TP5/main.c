#include "head.h"

int main()
{
    int n, totaljam, totalmenit;
    scanf("%d", &n); //jumlah data
    
    //scan
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", &mantra[i].nama, &mantra[i].mp, &mantra[i].waktu);
        mantra[i].hasilbagi = mantra[i].mp / mantra[i].waktu;
        totaljam += mantra[i].waktu;
        totalmenit += mantra[i].waktu;
    }
    //hasilwakatu diakhir
    totaljam /= 60; 
    totalmenit %= 60; 

    //scan tipe sorting
    char sort;
    scanf(" %c", &sort);
    //efektif/tidak
    char tipe[20];
    scanf("%s", &tipe);

    //tipe sorting
    if (sort == 'b') 
    {
        bs(n);
    }
    else
    {
        qstengah(0, n - 1); 
    }
    //cetak
    printoutput(n, totaljam, totalmenit);

    return 0;   
}