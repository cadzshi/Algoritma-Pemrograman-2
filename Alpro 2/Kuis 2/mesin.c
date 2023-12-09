#include "head.h"

void swap(data *a, data *b)
{
    data temp; 
    temp = *a; 
    *a = *b;   
    *b = temp; 
}

// Prosedur sorting dengan selection sort
void sorting(data temp[], int n, char urut[])
{
    int minidx, i, j;
    if (strcmp(urut, "banyak") == 0)
    {
        for (i = 0; i < n - 1; i++) 
        {
            minidx = i; 
            for (j = i + 1; j < n; j++)
            {
                if (temp[minidx].jmlTerjual > temp[j].jmlTerjual) 
                {
                    minidx = j;
                }
            }
            swap(&temp[minidx], &temp[i]); 
        }
    }
    else
    {
        for (i = 0; i < n - 1; i++) 
        {
            minidx = i; 
            for (j = i + 1; j < n; j++)
            {
                if (temp[minidx].penjualan < temp[j].penjualan) 
                {
                    minidx = j;
                }
            }
            swap(&temp[minidx], &temp[i]); 
        }
    }
    
}

// Prosedur searching dengan binary search
void search(data motor[], int n, long long int cari, char urut[])
{
    int flag = 0;
    int i = 0, k = 0;
    
    // While untuk proses binary search
    while ((i <= n) && (flag == 0))
    {
        // Set nilai k
        k = (int)(i + n) / 2;

        // Jika urut berdasarkan 
        if (strcmp(urut, "banyak") == 0)
        {
            // Jika data yang dicari ketemu
            if (motor[k].jmlTerjual == cari)
            {
                flag = 1;
                printf("%s %s %s %d %llu\n", motor[k].kodeMotor, motor[k].merkMotor, motor[k].tipeMotor, motor[k].jmlTerjual, motor[k].hargaMotor);

            }
            // Jika tidak
            else
            {
                // Setting nilai index
                if (motor[k].jmlTerjual > cari)
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        }
        // Jika urut berdasarkan penjualan
        else
        {
            // Jika data yang dicari ketemu
            if (motor[k].penjualan == cari)
            {
                flag = 1;
                printf("%s %s %s %d %llu\n", motor[k].kodeMotor, motor[k].merkMotor, motor[k].tipeMotor, motor[k].jmlTerjual, motor[k].hargaMotor);
            }
            // Jika tidak
            else
            {
                // Setting index
                if (motor[k].penjualan < cari)
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        }
    }

    // Output bila motor tidak ditemukan
    if (flag == 0)
    {
        printf("tidak ditemukan\n\n");
    }
}
