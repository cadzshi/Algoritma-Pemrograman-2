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
#include <stdlib.h>

// menampung record pada tabel
typedef struct
{
    char record[3][100];
} data;

//deklarasi variabel
int idx, wlen, banyakdata[2], a, b, c, longeststr[2][3];  //index, word length, banyak tabel, indeks pisahkata, kata terpanjang 
char cw[501], query[4][20], tabel[3][20], record[4][100]; //current word, query masukan, query tabel, query value
data umkm[100];                                           //record dalam tabel umkm
data pembeli[100];                                       // record dalam tabel pembeli

//deklarasi prosedur
void STARTKATA(char str[]);
void RESETKATA();
int EOPKATA(char input[]);
void INCKATA(char input[]);
int GETLEN();
char *GETCW();
int COMPAREKATA(char str1[], char str2[]);
void COPYKATA(char str1[], char str2[]);
void AMBILDATA();
void PISAHKATA(char str[]);
void FINDLONGEST();
void GARISTABEL(int u, int n, int p);
int CHECKEOP(char input[]);

// Prosedur untuk menjalankan input
int ISI();
int TAMPIL();

