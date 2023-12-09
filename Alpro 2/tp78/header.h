/*
    Saya Achmad Fauzan NIM 2108061 mengerjakan soal Tugas Praktikum 7 & 8 dalam
    mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // tambahan library untuk system("cls")

typedef struct film // struct untuk list film dan list film final
{
    // string sutradara, genre, dan bioskop bisa berisi id atau nama tergantung file yang diproses
    char judul[50], sutradara[50], genre[50], bioskop[50];
}
film;

typedef struct data // struct untuk sutradara, genre, dan bioskop
{
    char id[5], nama[50];
}
data;

// deklarasi variable pointer ke file
FILE* f_list_film;
FILE* f_sutradara;
FILE* f_genre;
FILE* f_bioskop;
FILE* f_list_film_final;

// deklarasi array untuk masing-masing file
film a_list_film[50];
data a_sutradara[50];
data a_genre[50];
data a_bioskop[50];
film a_list_film_final[50];

// deklarasi ukuran array
int n_list_film;    // tidak perlu ada n_list_film_final karena array list film final bergantung pada array list film
int n_sutradara;
int n_genre;
int n_bioskop;

// deklarasi fungsi dan prosedur
void init();
void fscanf_film(FILE*, char[], film[]);
void fscanf_data(FILE*, char[], data[], int*);
void fprintf_film(FILE*, char[], film[]);
void fprintf_data(FILE*, char[], data[], int);
void printf_film(film[]);
void printf_data(data[], int);
void garis_film(int, int, int, int);
void garis_data(int);
void proses_list_film_final();
data binary_search(data[], int, int, char[]);
void cari_data(char);
void insert_film();
void insert_data(data[], int*, char);
void menu_utama();
void menu_print();
void menu_cari();
void menu_insert();