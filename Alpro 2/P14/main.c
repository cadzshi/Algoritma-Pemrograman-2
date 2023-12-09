#include <stdio.h>
#include "head.h"


int main () 
{
    //menampilkan isi pita perkata
    // char pita[300];
    // printf ("masukkan pada kalimat pada pita\n");
    // scanf ("%299[^\n]s", &pita);

    // STARTKATA (pita);
    // printf ("%s\n", GETCKATA());

    // while (EOPKATA (pita) == 0) 
    // {
    //     INCKATA(pita);
    //     printf("%s\n", GETCKATA()) ;
    // }

    //menghitung banyak kata dalam pita
    char pita[300];
    int jkata = 0;
    printf("masukkan kalimat pada pita\n");
    scanf("%299[^\n]s", &pita);

    STARTKATA(pita);
    while(EOPKATA(pita) == 0) 
    {
        jkata++;
        INCKATA(pita);
    }
    if (GETPANJANGKATA() > 0)
    {
        jkata++;
    }
    printf("%d", jkata);
    
    return 0;
}