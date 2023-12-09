#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[100];
    int nilai;
} mahasiswa;

char namatukar[10];
int penampung(int n, int m, char namatukar[], mahasiswa data[n][m]);