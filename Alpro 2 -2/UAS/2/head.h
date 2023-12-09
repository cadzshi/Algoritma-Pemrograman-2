/*
    ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                 |
   | UAS no. 2 dalam mata kuliah Algoritma dan Pemrograman II  |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan  |
   | seperti yang telah dispesifikasikan. Aamiin               |
   =============================================================
*/

#include <stdio.h>
#include <string.h>

//deklarasi variabel global
int idx;
int wlen;
char cw[51];

// Bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);


// Bagian memajukan mesin kata
void inc(char str[]);


// Bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();