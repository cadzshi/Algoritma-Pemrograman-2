/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | TP 6 dalam mata kuliah Algoritma dan Pemrograman II |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <string.h>
#include <stdio.h>

typedef struct {
    char nama[50];
    int power;
    char spell[50];
} data;

void scandata(data murid[], int n);
void swap(data *a, data *b);
void sorting(data murid[], int n, char tipe[10]);
void merge(data murid1[], int n1, data murid2[], int n2, data murid3[], char tipe[10]);