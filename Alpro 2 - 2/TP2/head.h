/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | TP2 dalam mata kuliah Algoritma dan Pemrograman II       |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/
//Library
#include <stdio.h>
#include <string.h>
//deklarasi struct
typedef struct
{
    char nama[20];
    int ipa, mtk, eng;
} data; //nama struct
//variabel global
int n, m;
//fungsi dan prosedur
data* find_str(char str[], data awal[][m]);
float average(int a, int b, int c);
void swap(data* a, data* b);
void printhasil(data awal[][m]);