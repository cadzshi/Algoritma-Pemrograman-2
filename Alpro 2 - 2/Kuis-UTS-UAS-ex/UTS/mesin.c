#include "header.h"
void swap(data *a, data *b)
{
    data temp; // inisialisasi temp untuk tempat menyimpan data
    temp = *a; // simpan a di temp dulu
    *a = *b;   // a= b
    *b = temp; // b=temp atau b=a
}
void sorting(int n, data temp[], char tipesort[])
{
    int i, j;                        // ini untuk iterasi
    if (strcmp(tipesort, "ss") == 0) // jika selection sort
    {
        int index;                  // deklarasi index
        for (i = 0; i < n - 1; i++) // lalu ini for dengan batas n-1 karena nanti j nya ada j+1 agar tidak lebih
        {
            index = i; // simpan i di index
            for (j = i + 1; j < n; j++)
            {
                if (temp[index].hasil > temp[j].hasil) // jika hasil i lebih dari hasil j maka index= j
                {
                    index = j;
                }
            }
            swap(&temp[index], &temp[i]); // tuker index dengan i, jika tidak masuk di kondisi tadi maka tidak akan terjadi apa apa
        }
    }
    else if (strcmp(tipesort, "is") == 0) // jika insertion maka ascending
    {
        data tempp;
        for (i = 1; i < n; i++) // fornya batas n
        {
            int temp2 = temp[i].hasil;              // nah bikin temp2, untuk nyimpen hasil i karena akan dibandingkan
            tempp = temp[i];                        // terus tempp=temp[i], tempp adalah data lokal dari sini, temp adalah dari parameter
            j = i - 1;                              // iterator j
            while (j >= 0 && temp2 < temp[j].hasil) // nah jika hasil>temp
            {
                temp[j + 1] = temp[j]; // maka ganti temp j+1nya jadi temp j
                j--;                   // iterator --
            }
            temp[j + 1] = tempp; // lalu temp j+1 nya jadi tempp i
        }
    }
    else if (strcmp(tipesort, "bs") == 0)
    {
        int swapp;
        do // memakai do while karena harus menjalankan dulu baru masuk ke kondisi while
        {
            swapp = 0;                      // swapp =0 untuk memberhentikan kode
            for (int i = 0; i < n - 1; i++) // n-1 batasnya karena nantinya kan ada i+1 agar terakses semua
            {
                if (temp[i].hasil > temp[i + 1].hasil) // ini bandingkan, jika dia masuk ke kondisi ini(asc)
                {
                    swap(&temp[i], &temp[i + 1]);
                    swapp = 1; // nah jika dia tidak masuk ke kondisi ini maka swap akan 0 dan perulangan berhenti
                }
            }
        } while (swapp == 1);
    }
}
void qsorting(int kiri, int kanan, data tempp[])
{
    int i, j;
    double pivot;
    i = kiri, j = kanan;
    // i data kiri dan j kanan
    pivot = tempp[(kanan + kiri) / 2].hasil; // ini pivot hasil

    do
    {

        while ((tempp[i].hasil < pivot) && (i <= j))
        {
            i++;
            // i maju selama data ke-i lebih dari pivot dan nilai i kurang dari j
        }
        while ((tempp[j].hasil > pivot) && (i <= j))
        {
            j--;
            // j mundur selama data ke-j kurang dari pivot dan nilai i kurang dari j
        }

        if (i < j) // jika j>i, atau data berhenti, tuker datanya
        {
            swap(&tempp[i], &tempp[j]);
            i++; // iterator maju dan mundur lagi
            j--;
        }

    } while (i < j);
    // jika i sama dengan j datanya dibagi masuk ke rekursif
    if ((kiri < j) && (j < kanan))
    {
        qsorting(kiri, j, tempp);
    }
    if ((i < kanan) && (i > kiri))
    {
        qsorting(i, kanan, tempp);
    }
}
void merge(data temp1[], data temp2[], data result[], int a, int b)
{                                 // prosedur untuk menggabungkan kedua array yang sudah terurut
    int i = 0, j = 0, hitung = 0; // iterator index
    while ((i < a) && (j < b))    // selama i < panjang array1 dan j < panjang array2
    {
        if (temp1[i].hasil <= temp2[j].hasil) // jika data array1 lebih dari atau sama dengan data array2
        {
            result[hitung] = temp1[i]; // pindahkan isi struct array1 ke struct hasil(result)
            i++;                       // increment index kedua array of struct
            hitung++;
        }
        if (temp1[i].hasil >= temp2[j].hasil) // jika data array2 lebih dari atau sama dengan data array1
        {
            result[hitung] = temp2[j]; // pindahkan isi struct array2 ke struct hasil(result)
            j++;
            hitung++; // increment index kedua array of struct
        }
    }
    // jika masih ada sisa data dari pengisian array hasil sebelumnya
    if (i < a) // jika sisa di array 1
    {
        for (int k = i; k < a; k++)
        {
            result[hitung] = temp1[k]; // tambahkan sisa ke hasil
            hitung++;
        }
    }
    if (j < b) // jika di aray 2
    {
        for (int k = j; k < b; k++)
        {
            result[hitung] = temp2[k]; // tambahkan sisa ke  hasil
            hitung++;
        }
    }
}