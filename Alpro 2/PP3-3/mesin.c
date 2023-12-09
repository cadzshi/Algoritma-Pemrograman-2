#include "header.h"

void rekursif(int a, int b)
{
    if (a == 0)
    {
        return;
    }
    else
    {
        printf("%d - %d\n", a, b);
        rekursif(a / 2, b * 2);
    }
}