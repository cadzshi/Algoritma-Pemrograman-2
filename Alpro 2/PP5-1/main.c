#include "header.h"

int main()
{
    int n;
    scanf("%d", &n);

    data angka[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &angka[i].pembilang, &angka[i].penyebut);
    }

    char metode;
    scanf(" %c", &metode);

    switch (metode)
    {
    case 'b':
        bubblesort(n, angka);
        printhasil(n, angka);
        break;
    case 'q':
        quicksort(angka, 0, n -1);
        printhasil(n, angka);
        break;
    }
    return 0;
}
