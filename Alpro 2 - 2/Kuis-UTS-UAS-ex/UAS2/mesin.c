#include "header.h"
void hitungtemp(char pita[])
{
    int idx = 0;
    while (pita[idx] != '\0') // ketika belum menemukan null
    {
        idx++; // idx++
    }
    panjangtemp = idx; // panjangtemp=idx
}
void STARTKATA(char pita[])
{
    indeks = 0;
    panjangkata = 0;

    while (pita[indeks] == ' ')
    {
        indeks++;
    }

    while ((pita[indeks] != ' ') && (EOPKATA(pita) == 0))
    {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }

    int flag = 0;
    int i = 0;
    ckata[panjangkata] = '\0';
    // ini adalah algoritma untuk mencari kata yg samanya
    while (i < panjangkata && flag == 0) // while batas panjang kata dan kasih flag agar tidak kemasukkan 2x
    {
        int sama = 0;
        for (int j = 0; j < panjangtemp; j++) // jika nemu yg sama di karakter, ++sama
        {
            if (ckata[i + j] == temp[j])
            {
                sama++;
            }
        }
        if (sama == panjangtemp && flag == 0) // kalo yang samanya sama dengan panjang temp baru copy ke var simpan
        {
            for (int i = 0; i < panjangkata; i++)
            {
                simpan[count][i] = ckata[i];
            }
            count++;
            flag = 1;
        }
        i++;
    }
}

void RESETKATA()
{
    panjangkata = 0;
    ckata[panjangkata] = '\0';
}

void INCKATA(char pita[])
{
    panjangkata = 0;
    int index;
    while (pita[indeks] == ' ')
    {
        indeks++;
    }

    while ((pita[indeks] != ' ') && EOPKATA(pita) == 0)
    {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    int flag = 0;
    int i = 0;
    ckata[panjangkata] = '\0';
    while (i < panjangkata && flag == 0) // yg ini tidak ada bedanya seperti start yg tadi
    {
        int sama = 0;
        for (int j = 0; j < panjangtemp; j++) // jadi caro dulu yg sama perkarakter
        {
            if (ckata[i + j] == temp[j])
            {
                sama++;
            }
        }
        if (sama == panjangtemp) // jika yg samanya sama dengan panjang temp maka  copy arraynya kasih flag agar while berhenti

        {
            for (int i = 0; i < panjangkata; i++)
            {
                simpan[count][i] = ckata[i];
            }
            count++;
            flag = 1;
        }

        i++;
    }
}

char *GETCKATA()
{
    return ckata;
}

int GETPANJANGKATA()
{
    return panjangkata;
}

int EOPKATA(char pita[])
{
    if (pita[indeks] == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}