#include "header.h"

int main()
{
    char pita[501]; // deklarasi variabel

    scanf("%s %501[^\n]s", temp, pita); // scan
    hitungtemp(temp);                   /// hitung temp karena tidak bisa strlen
    count = 0;                          // deklarasi count=0 ini adalha jumlah kata
    STARTKATA(pita);

    while (EOPKATA(pita) == 0) // increment pita
    {
        INCKATA(pita);
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", simpan[i]);
    }

    return 0;
}
