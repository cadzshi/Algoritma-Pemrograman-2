#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[100];
    int nilai;
} mahasiswa;

int n, m;
char tukar[10], tukar2[10];

void scan (mahasiswa data[n][m]);
void tukarnilai (mahasiswa data[n][m]);
void print (mahasiswa data[n][m]);