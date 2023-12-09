/*Saya Muhammad Cahyana Bintang Fajar NIM 2102665 mengerjakan
 soal Uas no 2 dalam mata kuliah Algoritma dan Pemrograman 1
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
int indeks;
int panjangkata;

char ckata[501];
char temp[501];
char simpan[501][501];
int count;
int panjangtemp;
// ini mesin kata, saya mengubah start inc
void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
int GETPANJANGKATA();
char *GETCKATA();
int EOPKATA(char pita[]);
void hitungtemp(char pita[]); // hitung temp