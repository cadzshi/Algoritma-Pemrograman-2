#include "head.h"
/*
void scan (mahasiswa data[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%s", data[i][j].nama);
            scanf("%d", &data[i][j].nilai);
        }
    }
    
    scanf("%s", mhs);
    scanf("%s", mhs2);
}

void tukarnilai (mahasiswa data[n][m])
{
    int temp;
    int index1 = 0, index2 = 0, idx1 = 0, idx2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strcmp(tukar, data[i][j].nama) == 0)
            {
                index1 = i;
                index2 = j;
            }
            else if (strcmp(tukar2, data[i][j].nama) == 0)
            {
                idx1 = i;
                idx2 = j;
            }
        }
    }
    temp = data[idx1][idx2].nilai;
    data[idx1][idx2].nilai = data[index1][index2].nilai;
    data[index1][index2].nilai = temp;
}

void print (mahasiswa data[n][m])
{
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%s %d\n", data[i][j].nama, data[i][j].nilai);
        }
    }
}
*/

int penampung(int n, int m, char namatukar[], mahasiswa data[n][m])
{
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strcmp(namatukar, data[i][j].nama) == 0)
            {
                temp = data[i][j].nilai;
            }
        }
    }
    return temp;


}