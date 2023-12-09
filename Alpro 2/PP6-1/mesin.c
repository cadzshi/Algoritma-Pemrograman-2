#include "head.h"

void scandata(data arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", &arr[i].nama, &arr[i].nim);
    }
}

void printdata(data arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", arr[i].nim, arr[i].nama);
    }
}
void swapint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapstr(char a[], char b[])
{
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sorting(data arr[], int n)
{
    char temp[50];
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[minIdx].nama, arr[j].nama) > 0)
            {
                minIdx = j;
            }
        }
        swapstr(arr[i].nama, arr[minIdx].nama);
        swapint(&arr[i].nim, &arr[minIdx].nim);
    }
}

void merge(data arr1[], int n1, data arr2[], int n2, data arr3[])
{
    int i1 = 0, i2 = 0, i3 = 0;

    while ((i1 < n1) && (i2 < n2))
    {
        if (strcmp(arr1[i1].nama, arr2[i2].nama) <= 0)
        {
            strcpy(arr3[i3].nama, arr1[i1].nama);
            arr3[i3].nim = arr1[i1].nim;
            i3++;
            i1++;
        }
        else
        {
            strcpy(arr3[i3].nama, arr2[i2].nama);
            arr3[i3].nim = arr2[i2].nim;
            i3++;
            i2++;
        }
    }
    while (i1 < n1)
    {
        strcpy(arr3[i3].nama, arr1[i1].nama);
        arr3[i3].nim = arr1[i1].nim;
        i3++;
        i1++;
    }
    while (i2 < n2)
    {
        strcpy(arr3[i3].nama, arr2[i2].nama);
        arr3[i3].nim = arr2[i2].nim;
        i3++;
        i2++;
    }
    
}