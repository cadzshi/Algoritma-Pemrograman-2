#include "head.h"

int main()
{
    
    char tape[101];
    char kode = tape[0];
    int flag = 0;

    scanf("%101[^\n]s", &tape);


    start(tape);
    while (eop(tape) == 0)
    {
        inc(tape);
        check(tape, kode, flag);
    }

    if (flag == 1)
    {
        printf("Pesan rahasia yang dikirim oleh codename %c.\n", kode);
    }
    else
    {
        printf("Bukan pesan rahasia.\n");
    }
    
    

    return 0;
}

