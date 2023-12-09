#include <stdio.h>
/*
//merge table tidak terurut
void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i3 = 0;


    for (int i1 = 0; i1 < n1; i1++)
    {
        arr3[i3] = arr1[i1];
        i3++;
    }


    for (int i2 = 0; i2 < n2; i2++)
    {
        arr3[i3] = arr2[i2];
        i3++;
    }
}

void printArr(int arr3[], int n1, int n2)
{
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}

int main()
{
    int n1 = 4, n2 = 6;
    int arr1[] = {3, 5, 6, 9};
    int arr2[] = {1, 4, 2, 8, 10, 7};
    int arr3[n1 + n2];

    merge(arr1, 4, arr2, 6, arr3);
    printArr(arr3, 4, 6);
    
    return 0;
}
*/
/*
//merge table terurut
void merge(int arr1[], int n1, int arr2[], int n2, int arr3[])
{
    int i1 = 0, i2 = 0, i3 = 0;


    // ulangi hingga arr1 habis atau arr2 habis
    while ((i1 < n1) && (i2 < n2))
    {
        // jika elemen teratas arr1 lebih kecil dari arr2
        if (arr1[i1] < arr2[i2])
        {
            // masukkan elemen teratas arr1 ke dalam arr3
            arr3[i3] = arr1[i1];
            i3++;
            i1++;
        }
        // jika elemen teratas arr1 lebih besar dari arr2
        else
        {
            // masukkan elemen teratas arr2 ke dalam arr3
            arr3[i3] = arr2[i2];
            i3++;
            i2++;
        }
    }


    // masukkan sisa arr1 jika ada
    while(i1 < n1)
    {
        arr3[i3] = arr1[i1];
        i3++;
        i1++;
    }
    // masukkan sisa arr2 jika ada
    while(i2 < n2)
    {
        arr3[i3] = arr2[i2];
        i3++;
        i2++;
    }
}

void printArr(int arr3[], int n1, int n2)
{
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}

int main()
{
    int n1 = 4, n2 = 6;
    int arr1[] = {3, 5, 6, 9};
    int arr2[] = {1, 2, 4, 7, 8, 10};
    int arr3[n1 + n2];

    printf("Merge Table Terurut\n");
    merge(arr1, 4, arr2, 6, arr3);
    printArr(arr3, 4, 6);

    return 0;
}
*/

