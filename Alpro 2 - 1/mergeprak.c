#include <stdio.h>

/*
//merge_tidak_terurut
void merge_tidak_terurut (int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i; //iterator arr1 dan arr2
    int hitung = 0; //penunjuk index arr3

    //memasukkan isi array pertama ke dalam array ketiga
    for (i = 0; i < n; i++)
    {
        arr3[hitung] = arr1[i];
    }
    //memasukkan isi array kedua ke dalam array ketiga
    for (i = 0; i < m; i++)
    {
        arr3[hitung] = arr2[i];
    }
}

int main()
{
    int i;
    int n, m;

    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n;i++)
    {
        scanf("%d", arr1[i]);
    }

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m;i++)
    {
        scanf("%d", arr2[i]);
    }

    int arr3[n + m];
    merge_tidak_terurut(arr1, n, arr2, m, arr3);
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}
*/

//merge_terurut
void merge_terurut(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0; //iterator arr1 dan arr2
    int hitung = 0; //petunjuk index arr3
    int sisa; //iterator sisa

    while ((i < n) && (j < m))
    {
        //jika isi arr1 lebih kecil dari isi arr2
        if (arr1[i] < arr2[j])
        {
            //masukkan isi arr1 ke arr3
            arr3[hitung] = arr1[i];
            //index arr1 dan arr3 ditambah
            i++;
            hitung++;
        }
        //jika isi arr2 lebih kecil dari isi arr1
        else if (arr2[j] < arr1[i])
        {
            //masukkan isi arr2 ke arr3
            arr3[hitung] = arr2[j];
            //index arr2 dan arr3 ditambah
            j++;
            hitung++;
        }
        //jika isi arr1 dan arr2 sama
        else
        {
            //masukkan isi arr1 ke arr3
            arr3[hitung] = arr1[i];
            i++;
            hitung++;

            //masukkan isi arr2 ke arr3
            arr3[hitung] = arr2[j];
            j++;
            hitung++;
        }
    }
    //jika arr1 memiliki sisa
    if (i < n)
    {
        //masukkan sisa arr1 ke arr3
        for (sisa = i; sisa < n; sisa++)
        {
            arr3[hitung] = arr1[sisa];
            hitung++;
        }  
    }
    //jika arr2 memiliki sisa
    if (j < m)
    {
        //masukkan sisa arr2 ke arr3
        for (sisa = j; sisa < n; sisa++)
        {
            arr3[hitung] = arr2[sisa];
            hitung++;
        }  
    }
    
}