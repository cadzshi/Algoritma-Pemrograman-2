#include "header.h"

void print(int b, int k)
{
     for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < k; j++)
        {
            printf("%d %d %d", piksel1[i][j].red, piksel1[i][j].green, piksel1[i][j].blue);
        }
    }
}



