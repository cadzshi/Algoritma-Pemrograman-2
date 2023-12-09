#include <stdio.h>
#include <string.h>

typedef struct dessert
{
    char nama[30], negara[30];
    int kalori, gram, harga;
    float kpg;  // kalori per gram
}
dessert;

void scanArray(dessert[], int, char[]);
void insertionSort(dessert[], int);
void selectionSort(dessert[], int);
void bubbleSort(dessert[], int);
void quickSort(dessert[], int, int);
void tukar(dessert*, dessert*);
void printArray(dessert[], int, char[]);
void mergeArray(dessert[], int, dessert[], int, dessert[]);