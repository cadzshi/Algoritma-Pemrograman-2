#include "header.h"

void rekursif(int a, int b, int deret)
{
    if (deret > 0)
    {
        printf("%d %d", a, b);
        rekursif(a - pengurang, b - pengurang, deret - 1);
    }
    else if (deret == 0)
    {
        printf("%d %d", a, b);
    }
}