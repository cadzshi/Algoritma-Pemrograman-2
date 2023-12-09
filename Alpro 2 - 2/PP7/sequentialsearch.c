#include <stdio.h>

int n = 7; //total angka pada array
int arr[] = {5, 8, 6, 7, 2, 1, 7};
int targetValue = 2;

// utility : mencari sebuah angka pada sebuah arrary
// returns value : 0 berarti data yang dicari tidak ada, 1 berarti data yang dicari ada
int sequentialsearch(int n, int arrOfInt[], int target)
{
    int found = 0; //penanda apkaah angka yang dicari sudah ditemukan
    int i = 0; //index

    //jika masih kurang dari n dan found masih bernilai 0, maka
    while(i < n && found == 0)
    {
        //cek apakah elemen dengan index ke i pada array adalah sama
        if (arrOfInt[i] == target)
        {
            //jika ya maka ubah nilai found
            found = 1;
        }
        else
        {
            //jika tidak maka maju ke index selanjutnya
            i++;
        }
    }
    //return fungsi
    return found;
}

int main()
{
    //panggil fungsi lalu cek nilai kembaliannya apakah 0
    if (sequentialsearch(n, arr, targetValue) == 0)
    {
        //jika tidak
        printf("tidak ketemu\n");
    }
    else
    {
        //jika ya
        printf("ketemu\n");
    }
    
    return 0;
}

