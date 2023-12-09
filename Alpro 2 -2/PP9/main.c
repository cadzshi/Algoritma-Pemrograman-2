#include <stdio.h>
#include "head.h"


int main()
{
    // deklarasi variabel pita
    char pita[50];


    // meminta masukan pita
    printf("Masukan pita : ");
    scanf("%49[^\n]s", &pita);


    // memulai mesin dan membaca pita
    START(pita);
    while (EOP() == 0)
    {
        printf("%c", GETCC());
        INC(pita);
    }


    printf("\n");


    return 0;
}
