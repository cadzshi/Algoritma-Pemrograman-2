#include <stdio.h>
#include <string.h>


// deklarasi tipe bungkusan mahasiswa
typedef struct
{
    char nim[20], nama[50], nilai[10];
} student;


// deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[50]; // kata saat ini (current word)


// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);


// bagian memajukan mesin kata
void inc(char str[]);


// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();


// prosedur dan fungsi tambahan
void modify_data(char str[], student *data);
