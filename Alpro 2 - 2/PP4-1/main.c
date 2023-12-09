#include "header.h"

int main()
{
    int n;
    scanf("%d", &n);
    char nama[n][50];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &nama[i]);
    }
    char metode[20];
    scanf("%s", &metode);

    printsorting(n, nama, metode);
    return 0;
}