#include "head.h"

int main()
{
    // deklarasi variabel pita
    char pita[50], temp;
    int n = 0;

    // meminta masukan pita
    scanf("%49[^\n]s", &pita);

    // memulai mesin, membaca pita, dan mengeluarkan output
    JUMLAHKATA(pita, temp, n);
    
    

    return 0;
}
