#include <stdio.h>

typedef struct
{
    int nama_variabel1;
    char nama_variabel2[100];
    char nama_variabel3[10];
} data;

int baris, kolom;

void scandata (data nama_matriks[baris][kolom]);
void printdata (data nama_matriks[baris][kolom]);