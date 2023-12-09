#include "header.h"

int main()
{
    int n1, n2, n3;
    char metode[3];
    char negara1[30], negara2[30], negara3[30];

    scanf("%s", metode);

    scanf("%s", negara1);
    scanf("%d", &n1);
    dessert array1[n1];
    scanArray(array1, n1, negara1);

    scanf("%s", negara2);
    scanf("%d", &n2);
    dessert array2[n2];
    scanArray(array2, n2, negara2);

    scanf("%s", negara3);
    scanf("%d", &n3);
    dessert array3[n3];
    scanArray(array3, n3, negara3);

    if (strcmp(metode, "is") == 0)
    {
        insertionSort(array1, n1);
        insertionSort(array2, n2);
        insertionSort(array3, n3);
    }
    else if (strcmp(metode, "ss") == 0)
    {
        selectionSort(array1, n1);
        selectionSort(array2, n2);
        selectionSort(array3, n3);
    }
    else if (strcmp(metode, "bs") == 0)
    {
        bubbleSort(array1, n1);
        bubbleSort(array2, n2);
        bubbleSort(array3, n3);
    }
    else if (strcmp(metode, "qs") == 0)
    {
        quickSort(array1, 0, n1 - 1);
        quickSort(array2, 0, n2 - 1);
        quickSort(array3, 0, n3 - 1);
    }

    printf("Per Negara:\n");
    printArray(array1, n1, negara1);
    printArray(array2, n2, negara2);
    printArray(array3, n3, negara3);

    dessert temp[n1 + n2], akhir[n1 + n2 + n3];

    mergeArray(array1, n1, array2, n2, temp);
    mergeArray(temp, n1 + n2, array3, n3, akhir);

    printf("Semua:\n");
    for (int i = 0; i < n1 + n2 + n3; i++)
    {
        printf("- %s %s %d %d %d - ", akhir[i].negara, akhir[i].nama, akhir[i].kalori, akhir[i].gram, akhir[i].harga);
        if (akhir[i].kalori % akhir[i].gram == 0) printf("%.0f\n", akhir[i].kpg);
        else printf("%.2f\n", akhir[i].kpg);
    }

    return 0;
}