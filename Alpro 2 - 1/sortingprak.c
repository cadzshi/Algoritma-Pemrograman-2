#include <stdio.h>

/*
//insertion sorting
//prosedur untuk menampilkan isi array
void printarray(int n, int array[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        //menampilkan isi array
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int i, j, key;
    int array[8] = {6, 3, 4, 7, 2, 5, 8, 1};

    //menampilkan isi array sebelum sorting
    printf("array sebelum sorting:\n");
    printarray(8, array);

    //perulangan dilakukan sebanyak isi array yang dimilai dari index 1
    for ( i = 0; i < 8; i++)
    {
        //array ke-i akan menjadi data untuk sisipkan
        key = array[i];
        j = i -1;

        //perulangan terhadap isi array yang berada sebelum index ke-i
        //perulangan berlangsung hingga mencapai  index ke-0 atau selama
        //array ke-j nilainya lebih besar dari key (array[j] > key)

        while ( j >= 0 && key < array[j] )
        {
            //geser array ke kanan
            array[j + 1] = array[j];
            j--;

            ////menempatkan key pada array[j + 1]
            array[j + 1] = key;
        }
    }
    //menampilkan array setelah sorting array
    printf("\nArray setelah sorting (insertion):\n");
    printarray(8, array);

    return 0;
}
*/
//selection sorting
//prosedur untuk menampilkan isi array

void printarray(int n, int array[]) 
{
    int i;
    for(i=0; i<n; i++)
    {
        //menampilkan isi array
        printf("%d");
    }
}