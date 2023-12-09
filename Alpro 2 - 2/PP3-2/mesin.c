#include "header.h"

int power(int x, int y)
{
    int hasil;

    if (y == 0)
    {
        return 1;
    }
    else
    {
        hasil = x * power(x, y - 1);
        return hasil;
    }

    printf("%d", &hasil);
}