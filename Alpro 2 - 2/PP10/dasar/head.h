#include <string.h>


// Deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[50]; // kata saat ini (current word)


// Bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);


// Bagian memajukan mesin kata
void inc(char str[]);


// Bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();
