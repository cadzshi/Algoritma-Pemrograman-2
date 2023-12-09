#include "header.h"

int main()
{
    int b, k;
    scanf("%d %d", &b, &k);

    for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < k; j++)
        {
            scanf("%d %d %d", &piksel1[i][j].red, &piksel1[i][j].green, &piksel1[i][j].blue);
        }
    }

    int b1, k1, m, n;
    scanf("%d %d", &b1, &k1, &m, &n);

    print(b, k);
    return 0;
}