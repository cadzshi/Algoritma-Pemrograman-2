#include <stdio.h>
#include "head.h"


int main()
{
    // deklarasi variabel pita
    char tape[128];


    // meminta masukan
    printf("Masukkan pita : ");
    scanf("%127[^\n]s", &tape);


    // memulai mesin kata dan membaca pita
    start(tape);
    printf("%s\n", getcw());


    while (eop(tape) == 0)
    {
        inc(tape);
        printf("%s\n", getcw());
    }


    return 0;
}
