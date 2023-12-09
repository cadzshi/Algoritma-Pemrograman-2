#include <stdio.h>
/*
//bubble sort
void bubbleSort(int n, int array[])
{
    int i, temp, swap;
    //perulangan hingga seluruh data tidak ada yang ditukar
    do
    {
        //nilai swap untuk penanda apakah ada data yang ditukar
        swap = 0; //inisialisasi swap dengan nilai 0;

        //cek semua data 
        for (i = 0; i < (n - 1); i++)
        {
            //jika data ke-i lebih besar dari data ke i+1
            if (array[i] > array[i + 1])
            {
                //tukar data
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                //tanda bahawa ada data yang ditukar
                swap = 1;
            }
        } 
    } while (swap == 1);
} 
int main()
{
    int i, j;
    int array[8] = {6, 3, 4, 7, 2, 5, 8, 1};

    //menampilkan array sebelum sorting   
    printf("array sebelum sorting:\n");
    printArray(8, array);

    //melakukan sorting   
    bubbleSort(8, array);

    //menampilkan array setelah sorting
    printf("array setelah sorting (bubble sort):\n");
    printArray(8, array);

    return 0;
}
*/

//quick sort (pivot pinggir)
void qspinggir(int array[], int kiri, int kanan)
{
    int i, j, temp;
    i = kiri; j = kanan;

    do
    {
    //perulangan untuk menggeser i dan j
    while ((array[i] < array[kanan]) && (i <= j))
    {
        i++;
    }
    while((array[j] > array[kiri]) && (i <= j))
    {
        j--;
    }
    if (i < j)
    {
        //tukar data i dan j
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        i++; j--;
    }
    }while(i < j);

    //sorting sub-bagian (kiri dan kanan)
    if(kiri < j)
    {
        qspinggir(array, kiri, j);
    }
    if (i < kanan)
    {
        qspinggir(array, i, kanan);
    }
}

int main()
{
    int array[8] = {34, 67, 23, 98, 15, 89, 67, 18};
    int n = 8;

    //menampilkan array sebelum sorting
    printf("array sebelum sorting:\n");
    printarray(n, array);

    //melakukan sorting
    qspinggir(array, 0, n-1);

    //menampilkan array setelah sorting
    printf("array setelah sorting (pivot pinggir):\n");
    printarray(n, array);

    return 0;
}

//pivot tengah