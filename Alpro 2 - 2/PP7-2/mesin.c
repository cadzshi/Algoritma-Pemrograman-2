#include "head.h"

void swap(data temp[], int a, int b)
{
    data tempp = temp[a];
    temp[a] = temp[b];
    temp[b] = tempp;
}

void sort(int n, data arr[])
{
    int flag = 1;
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].nim > arr[i + 1].nim)
            {
                swap(arr, i, i + 1);
                flag = 0;
            }
        }
    } while (flag == 0);
}

void search(data arr[], int n, int target)
{
    int i = 0, j = n - 1, mid; 
    int found = 0; 

    while (found == 0 && i <= j)
    {
        mid = (i + j) / 2;
        if (arr[mid].nim == target)
        {
            printf("%d\n", arr[mid].nim);
            printf("%s\n", arr[mid].nama);
            printf("%s\n", arr[mid].kelas);
            found = 1;
        }
        else
        {
            if (arr[mid].nim >= target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid - 1;
            }
        }
    }
}

