/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | TP5 dalam mata kuliah Algoritma dan Pemrograman II       |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/
//library
#include <string.h>
#include <stdio.h>
//bungkusan
typedef struct{
    char nama[50];
    int mp, waktu, hasilbagi;
} data;
//bungkusan global n prosedur
data temp;
data mantra[100];
void tukar(int idx1, int idx2) ;
void bs(int n);
void qstengah(int kiri, int kanan);
void printoutput(int n, int totaljam, int totalmenit);