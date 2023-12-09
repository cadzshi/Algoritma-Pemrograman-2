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
    int arr[8] = {6, 3, 4, 7, 2, 5, 8, 1};
    int minIndex, temp;
    printf("Sebelum di sort:\n");
    printArr(arr);
    // algoritma selection sort
    for (i = 0; i < (8 - 1); i++)
    {
        minIndex = i;
        for (j = i+1; j < 8; j++)
        {
            if (arr[minIndex] < arr[j])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }


    printf("Setelah di sort:\n");
    printArr(arr);
    return 0;
}
