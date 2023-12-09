/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | TP 7 dalam mata kuliah Algoritma dan Pemrograman II      |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[20];
    int berat, nilaiguna;
} data;

void scandata(int n, data barang[]);
void print(int n, data barang[]);