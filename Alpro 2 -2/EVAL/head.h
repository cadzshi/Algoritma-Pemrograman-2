/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan soal           |
   | Evaluasi dalam mata kuliah Algoritma dan Pemrograman II  |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/


#include <stdio.h>
#include <string.h>


//deklarasi variabel global
int idx, wlen, terpanjang[3], banyakdata;
char cw[501];
char tiket[100][3][100];

// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);

// bagian memajukan mesin kata
void inc(char str[]);

// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();

//bagian output
void prosedur(int i, char pita[]);
void cariterpanjang(int i);
void output(int i);




