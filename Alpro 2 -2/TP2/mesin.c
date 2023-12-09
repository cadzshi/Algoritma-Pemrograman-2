#include "head.h"

//fungsi nyari string di dalam matrix
data* find_str(char str[], data akhir[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strcmp(str, akhir[i][j].nama) == 0) 
            {
                return &akhir[i][j];
            }
        }
    }
    return NULL;
}
//fungsi nyari rata rata nilai
float average(int a, int b, int c)
{
    return ((float)a + (float)b + (float)c / 3);
}
//prosedur nukar posisi
void swap(data* a, data* b)
{
    data temp = *a;
    *a = *b;
    *b = temp;
}
//prosedur untuk pirnt output
void printhasil(data akhir[][m])
{
    int spasi, panjang[m];  //variabel lokal
    for (int j = 0; j < m; j++)
    {
        //nyari jumlah string terpanjang
        panjang[j] = 0;
        for (int i = 0; i < n; i++)
        {
            if (strlen(akhir[i][j].nama) > panjang[j]) 
            {
                panjang[j] = strlen(akhir[i][j].nama);
            }
        }
    }
    //baru diprint
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            printf("%s", akhir[i][j].nama);
            if (j < m - 1)
            {
                spasi = panjang[j] - strlen(akhir[i][j].nama) + 2;
                for (int k = 0; k < spasi; k++)
                {
                    printf(" ");
                }
            }
            else
            {
                printf("\n");
            }
        }
    }
}