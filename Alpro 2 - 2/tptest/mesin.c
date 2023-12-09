#include "head.h"

void insertion_sort(char arr[])
{
    for (int i = 1; i < n; i++)
    {
        char temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selection_sort(char arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[idx]) idx = j;
        }
        swap(&arr[i], &arr[idx]);
    }
}

void bubble_sort(char arr[])
{
    int sorted;
    for (int i = 0; i < n - 1; i++)
    {
        sorted = 1;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                sorted = 0;
            }
        }
        if (sorted == 1) return;
    }
}

void quick_sort(char arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int partition(char arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}