#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50], jurusan[50], fakultas[50];
}
mhs;

typedef struct 
{
    char id[5], nama[50];
}
data;

FILE* f_mhs;
FILE* f_jurusan;
FILE* f_fakultas;
FILE* f_mhsfinal;

mhs a_mhs[50];
data a_jurusan[50];
data a_fakultas[50];
mhs a_mhsfinal[50];

int n_mhs;
int n_jurusan;
int n_fakultas;

void proses();
data binary_search(data a[], int l, int r, char s[]) ;
void printmhs(mhs a[]);
void fscanf_data(FILE* f, char s[], data a[], int* n);
void fscanf_mhs(FILE* f, char s[], mhs a[]);
void init();