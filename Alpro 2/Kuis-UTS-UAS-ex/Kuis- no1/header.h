/*Saya Muhammad Cahyana Bintang Fajar NIM 2102665 mengerjakan
 soal Kuis 1 No 1 dalam mata kuliah Algoritma dan Pemrograman 1
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h> //panggil header
typedef struct     // deklarasi struct
{
    int a, b; // a pembilang b penyebut
} data;
// deklarasi variabel matriks
data matriks1[100][100];
data matriks2[100][100];
data matriks3[100][100];                                    // ini untuk output
int index1, index2;                                         // ini untuk nandain index nantinya
void solve(int a, int b, int c, int d, int idx1, int idx2); // prosedur solve/ penyelesaian masalah
void print(int baris, int kolom);                           // print matriks