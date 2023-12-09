/*
    ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                 |
   | UAS no. 1 dalam mata kuliah Algoritma dan Pemrograman II  |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan  |
   | seperti yang telah dispesifikasikan. Aamiin               |
   =============================================================
*/

#include <stdio.h>
// mendeklarasikan  variabel global
int idx; // untuk indeks saat ini
char cc; // untuk menampung karakter saat ini

// deklarasi fungsi dan prosedur yang akan dibuat
void start(char kalimat[]); // memulai mesin
int eop();                  // sebagai penanda mesin berakhir

void inc(char kalimat[]); // menambah indeks pada mesin

int getidx(); // untuk mendapatkan nilai indeks saat ini
char getcc(); // untuk mendapatkan karakter saat ini
void adv(char pita[]);