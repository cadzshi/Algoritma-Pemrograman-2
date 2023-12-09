#include "header.h"

void scanArray(dessert array[], int size, char negara[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%s %d %d %d", array[i].nama, &array[i].kalori, &array[i].gram, &array[i].harga);
        strcpy(array[i].negara, negara);
        array[i].kpg = (float)array[i].kalori / array[i].gram;
    }
}

void insertionSort(dessert array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        dessert temp = array[i];
        int j = i - 1;
        while (temp.kpg > array[j].kpg && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void selectionSort(dessert array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int indexMax = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].kpg > array[indexMax].kpg) indexMax = j;
        }
        tukar(&array[indexMax], &array[i]);
    }
}

void bubbleSort(dessert array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (array[j - 1].kpg < array[j].kpg)
            {
                tukar(&array[j - 1], &array[j]);
            }
        }
    }
}

void quickSort(dessert array[], int left, int right)
{
    if (left < right)
    {
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (array[j].kpg > array[right].kpg)
            {
                tukar(&array[j], &array[i]);
                i++;
            }
        }
        tukar(&array[i], &array[right]);
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    }
}

void tukar(dessert* a, dessert* b)
{
    dessert temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(dessert array[], int size, char negara[])
{
    printf("%s\n", negara);
    for (int i = 0; i < size; i++)
    {
        printf("- %s %d %d %d - ", array[i].nama, array[i].kalori, array[i].gram, array[i].harga);
        if (array[i].kalori % array[i].gram == 0) printf("%.0f\n", array[i].kpg);
        else printf("%.2f\n", array[i].kpg);
    }
    printf("\n");
}

void mergeArray(dessert array1[], int size1, dessert array2[], int size2, dessert arrayHasil[])
{
    int index1 = 0, index2 = 0, indexHasil = 0;
    while (index1 < size1 && index2 < size2)
    {
        if (array1[index1].kpg >= array2[index2].kpg)
        {
            arrayHasil[indexHasil] = array1[index1];
            indexHasil++;
            index1++;
        }
        else
        {
            arrayHasil[indexHasil] = array2[index2];
            indexHasil++;
            index2++;
        }
    }
    if (index1 < size1)
    {
        while (index1 < size1)
        {
            arrayHasil[indexHasil] = array1[index1];
            indexHasil++;
            index1++;
        }
    }
    else
    {
        while (index2 < size2)
        {
            arrayHasil[indexHasil] = array2[index2];
            indexHasil++;
            index2++;
        }
    }
}