#include "head.h"

void search(int n, int num[], int target)
{
    int flag = 0;
    for (int i = 0; i < n; i ++)
    {
        if (num[i] % 100 / 10 == target)
        {
            printf("%d ", num[i]);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("Tidak ditemukan\n");
    }
}
