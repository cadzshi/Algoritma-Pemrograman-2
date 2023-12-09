/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan soal Evaluasi  |
   | TMD dalam mata kuliah Algoritma dan Pemrograman II       |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

// Library:
#include <stdio.h>
#include <string.h>

// Typedef struct untuk menampung record yang ada dalam file/tabel
typedef struct
{
    char value[3][100];
} record;

int idx, wlen, banyakrecord[1], a, b, c, longeststr[2][3];
char cw[501], query[4][20], tabel[3][20], value[4][100];
record umkm[100];

/*
    (1) idx = index
    (2) wlen = word length
    (3) banyakrecord = banyak record tiap tabel (0) untuk games | (1) untuk developer
    (4) a, b, c = untuk indeks untuk melakukan prosedur explode
    (5) kataterpanjang = menampung panjang kata terpanjang dalam tabel
    (6) cw = current word
    (7) query = menampung query masukkan user
    (8) tabel = menampung tabel masukkan user
    (9) value = menampung value masukkan user
    (10) record game = menampung record dalam tabel game
    (11) record developer = menampung record dalam tabel developer
*/

// Dijelaskan dalam mesin.c =>
void start(char word[]);
void reset();
int eop(char query[]);
void inc(char query[]);
int getlen();
char *getcw();
int COMPAREKATA(char word1[], char word2[]);
void COPYKATA(char word1[], char word2[]);
void ambildata();
void explode(char word1[]);
void FINDLONGEST();
int cek(char word[]);
void garis_tabel (int u, int n, int p);

// Prosedur untuk menjalankan query
int ISI();
int TAMPIL();
// int UBAH();