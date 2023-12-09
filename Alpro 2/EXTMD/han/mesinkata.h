/*
Saya Farhan Muzhaffar Tiras Putra NIM 2105879
mengerjakan Tugas Masa Depan dalam mata kuliah Algoritma dan Pemograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin.
*/

// Library yang digunakan
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// membuat tipe data bungkusan untuk menyimpan data riders
typedef struct
{
    char name[255];  // untuk nama rider
    char number[52]; // untuk nomer rider
    char cmotor[8];  // untuk kode motor
} riders;

// membuat tipe data bungkusan untuk menyimpan data motor
typedef struct
{
    char cmotor[8]; // untuk kode motor
    char motor[16]; // untuk nama motor
} motors;

// deklarasi variabel dan string global
int indeks, l, m, t;
char ckata[255];
char ID[255];
int panjangkata;
char cquery[255][255];
char data[255][255];

// deklarasi fungsi dan prosedur
void STARTKATA(char pita[]);
void INCKATA(char pita[]);
char *GETKATA();
int EOPKATA(char pita[]);
int CHECKQUERY(char input[], riders Rdata);
int CHECKQUERYMOTOR(char input[], motors Rdata);
int INDEXSEARCH();
void COUNTQUERY(char pita[]);
int CHECKTABLE(char input[]);
void GETDATA(char input[]);
char *GETID();
void QUERYINUSE(int query, char input[]);
int CHECKEOP(char input[]);
int CHECKCOLOUMN(char input[]);

int CHECKDATA(riders Rdata);
void ENTRI(char input[], riders Rdata);
void UBAH(char input[], riders Rdata);
void HAPUS(char input[], riders Rdata);
void TAMPIL(char input[], riders Rdata);

int CHECKDATAMOTORS(motors Rdata);
void ENTRIMOTOR(char input[], motors Rdata);
void UBAHMOTOR(char input[], motors Rdata);
void HAPUSMOTOR(char input[], motors Rdata);
void TAMPILMOTOR(char input[], motors Rdata);
