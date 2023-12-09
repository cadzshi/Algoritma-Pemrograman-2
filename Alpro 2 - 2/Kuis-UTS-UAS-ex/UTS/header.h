/*Saya Muhammad Cahyana Bintang Fajar NIM 2102665 mengerjakan
 soal UTS dalam mata kuliah Algoritma dan Pemrograman 1
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <string.h>
#include <stdio.h>

// ini struct untuk menyimpan data
typedef struct
{
    char str[50];             // ini untuk menyimpan namanya
    int kalori, lemak, harga; // ini kalori,lemak, harga
    double hasil;             // ini hasil yang koma
    int hasil2;               // int hasil karena untuk dibandingkan di print nanti
    int supplier;             // untuk menyimpan suppliernya 1,2, atau 3
} data;
void swap(data *a, data *b);                                         // ini untuk menukar
void sorting(int n, data temp[], char tipesort[]);                   // sorting untuk 3 tipe sort selain quick
void qsorting(int kiri, int kanan, data tempp[]);                    // prosedur quick
void merge(data temp1[], data temp2[], data result[], int a, int b); // prosedur merge
