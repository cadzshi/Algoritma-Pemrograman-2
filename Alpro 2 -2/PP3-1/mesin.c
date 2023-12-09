#include "header.h"

void rekursifAlphabet (char alphabet)
{
    printf("%c ", alphabet);
    if (alphabet > 'A') //base case
    {
        rekursifAlphabet (alphabet - 1); //rekursif
    }
}