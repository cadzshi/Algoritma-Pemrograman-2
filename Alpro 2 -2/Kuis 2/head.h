/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | Kuis 2 dalam mata kuliah Algoritma dan Pemrograman II    |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char kodeMotor[5];
    char merkMotor[20];
    char tipeMotor[10];
    int jmlTerjual;
    long long int hargaMotor;
    long long int penjualan;
} data;


void sorting(data motor[], int n, char urut[]);
void search(data motor[], int n, long long int cari, char urut[]);
