#include <stdio.h>
/*
//insention sort
int main()
{
    int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
    int i;
    int data_sisip;
    int j;

    for (i = 0; i < 10; i++)
    {
        data_sisip = tabInt[i];
        j = i - 1;

        while ((data_sisip < tabInt[j]) && (j >= 0))
        {
            //jika data array lebih kecil dari data sisip 
            //maka data data array digeser ke belakang   
            tabInt[j + 1] = tabInt[j];
            j = j - 1;
        }
        //menempatkan data sisip pada array
        tabInt[j + 1] = data_sisip;
    }
    return 0;
}
*/

//selection sort 
int main ()
{
    int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
    int i; int temp; int minIndeks; int j;
    for ( i = 0; i < (10 - 1); i++)
    {
        //inisialisasi indeks elemen minimum
        minIndeks = i;
        //perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen array
        for (j = 0; j < 10; j++)
        {
            if (tabInt[minIndeks] > tabInt[j])
            {
                minIndeks = j;
            }
        }
        //menukar posisi elemen
        temp = tabInt[i];
        tabInt[i] = tabInt[minIndeks];
        tabInt[minIndeks] = temp;

        printf("%d ", tabInt[minIndeks]);
    }
    return 0;
}
