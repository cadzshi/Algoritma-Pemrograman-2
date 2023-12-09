#include "header.h"

//prosedur bubblesort
void bubblesort (int n, data angka[])
{
    int swap, temp, i, j;
    do
    {
        swap = 0; 
        for (i = 0; i < n - 1; i++)
        { 
            for (j = 0; j < n - i - 1; j++)
            {
                if ((angka[j].pembilang * angka[j + 1].penyebut) > (angka[j + 1].pembilang * angka[j].penyebut))
                { 
                    temp = angka[j].pembilang;
                    angka[j].pembilang = angka[j+1].pembilang;
                    angka[j+1].pembilang = temp;

                    temp = angka[j].penyebut;
                    angka[j].penyebut = angka[j+1].penyebut;
                    angka[j+1].penyebut = temp;
                    swap = 1;
                }
            }
            
            
        }
    } while (swap  == 1);
}
//quicksort masih salah bang :'''''''''
int fpb(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return fpb(b, a % b);
}

void sederhana(data *p) 
{
    int f = fpb(p->pembilang, p->penyebut);
    p->pembilang /= f;
    p->penyebut /= f;
}

int compare(data a, data b) 
{
    int x = a.pembilang * b.penyebut;
    int y = b.pembilang * a.penyebut;
    
    if (x < y) 
    {
        return -1;
    } 
    else if (x == y) 
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
}

void swap(data *a, data *b) 
{  
   data temp = *a;
   *a = *b;
   *b = temp;
}

int partition(data angka[], int kiri, int kanan) 
{
    data pivot = angka[kanan];
    int i = kiri -1;
    for (int j=kiri; j<kanan; j++) 
    {
        if (compare(angka[j],pivot)<=0)
        {
        i++;
        swap(&angka[i],&angka[j]);
        }
    }
    swap(&angka[i+1],&angka[kanan]);
    return i+1;

}
 
void quicksort(data angka[], int kiri, int kanan)
{
    if(kiri < kanan)
    {
        int pi=partition(angka,kiri,kanan);
        quicksort(angka,kiri,pi-1);
        quicksort(angka,pi+1,kanan);
    }

}

//print hasil
void printhasil (int n, data angka[])
{
    for (int i = 0; i < n; i++)
        {
            printf("%d ", angka[i].pembilang);
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("- ");
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", angka[i].penyebut);
        }
}
