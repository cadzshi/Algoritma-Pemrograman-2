/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | UTS dalam mata kuliah Algoritma dan Pemrograman II       |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[100];
    int gula;
    int karbo;
    int protein;
    int hasil;
} data;

void scandata(data menu[], int n, int jmlmenu, int jmlgula, int jmlkarbo, int jmlprotein);
void swap(data *a, data *b);
void sorting(data menu[], int n, char tipe[]);
void qsorting(data menu[], int n);
void merge(data temp1[], int n1, data temp2[], int n2, data temp3[]);
void print(int n, data menu[]);