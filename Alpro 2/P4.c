#include <stdio.h>

/*
//insertion sort
int main()
{
    int arr[100], datasisip, n, i, j;;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (j = 1; j  < n; j ++)
    {
        datasisip = arr[i];
        j = i - 1;   
    }

    while (datasisip < arr[j] && j >= 0)
    {
        //jik data array lebih kecil dari data sisip maka data array digeser ke belakang
        arr[j  +1] = arr[j];
        j--;
    }
    
    arr[j + 1] = datasisip;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[j]);
    
*/
    //selection sort
int main()
    {
        int arr[10] = {34, 67, 28, 23, 98, 15, 29, 38, 18};
        int i, temp, j, min, max;

        for (i = 0; i < 10 - 1; i++)
        {
            min = i;
            for (j = 0; j < 10; j++)
            {
                if (arr[min] > arr[j])
                {
                    min = j;
                }
                
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        
        return 0;
    }
    
    
