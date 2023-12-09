/*
   ============================================================
   | Saya Sabila Rosad NIM 2106000 mengerjakan                |
   | TP 8 dalam mata kuliah Algoritma dan Pemrograman II      |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/
//library
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//struct list laptop
typedef struct {
    char listLaptop[50], processor[50], merk[50], ram[50];
} laptop;
//struct spesifikasi laptop
typedef struct {
    char id[5], nama[50];
} data;
//deklarasi var pointer ke file
FILE* f_listLaptop;
FILE* f_processor;
FILE* f_merk;
FILE* f_ram;
//deklarasi array masing masing file
laptop a_listLaptop[50];
data a_processor[50];
data a_merk[50];
data a_ram[50];
//ukuran array
int n_listLaptop;
int n_processor;
int n_merk;
int n_ram;
//deklarasi prosedur
void init();
void fscanf_laptop(FILE* f, char s[], laptop a[]);
void fscanf_data(FILE* f, char s[], data a[], int* n);
void fprintf_laptop(FILE* f, char s[], laptop a[]);
void fprintf_data(FILE* f, char s[], data a[], int n);
void printf_laptop(laptop a[]);
void printf_data(data a[], int n);
void inserData(data a[], int* n, char c);
void insertLaptop();
void garis_tabel(int l, int p, int m, int r);
void garis_tabel2(int q);
void menuUtama();
void menuPrint();
void menuInsert();