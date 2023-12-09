#include <stdio.h>

typedef struct 
{
    int pembilang;
    int penyebut;
} data;

void bubblesort (int n, data angka[]);
void quicksort (data angka[], int kiri, int kanan);
void printhasil (int n, data angka[]);