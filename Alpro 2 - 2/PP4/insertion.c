#include <stdio.h>

void printArr(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int key, i, j;
    int arr[8] = {6, 3, 5, 8, 7, 1, 2, 4};

    printf("Sebelum di sort:\n");
    printArr(arr);

    //algoritma
    for (i = 0; i < 8; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Setelah di sort:\n");
    printArr(arr);
    
    return 0;
}