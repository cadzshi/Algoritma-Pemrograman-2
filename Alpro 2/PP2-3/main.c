#include "head.h"

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    mahasiswa data[n][m];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%s", data[i][j].nama);
            scanf("%d", &data[i][j].nilai);
        }
    }

    char mhs[10], mhs2[10];
    scanf("%s", mhs);
    scanf("%s", mhs2);

    int temp1 = penampung(n, m, mhs, data);
    int temp2 = penampung(n, m, mhs2, data);

    int nilaimax = 0;
    char orgmax[50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nilaimax < data[i][j].nilai)
            {
                nilaimax = data[i][j].nilai;
                strcpy(orgmax, data[i][j].nilai);
            }
            
        }
        
    }

    printf("\nSebelum ditukar :\n%s %d\n\n", orgmax, nilaimax);
    nilaimax = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strcmp(mhs, data[i][j].nama) == 0)
            {
                data[i][j].nilai = mhs2;
            }
            if (strcmp(mhs2, data[i][j].nama) == 0)
            {
                data[i][j].nilai = mhs;
            }
            if (nilaimax < data[i][j].nilai)
            {
                nilaimax = data[i][j].nilai;
                strcpy(orgmax, data[i][j].nilai);
            }
            printf("%s %d\n", data[i][j].nama, data[i][j].nilai);
        }
        
    }
    

    return 0;
}