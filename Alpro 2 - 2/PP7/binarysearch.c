#include <stdio.h>

int n = 10; //total angka pada array
int arr[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; //data harus diurut
int targetValue = 17; //data yang dicari 

//utility : mencari sebuah angka pada sebuah array yang terurut
// return value: 0 berarti data yang dicari tidak ada, 1 berarti data yang dicari ada
int binarySearch(int n, int arrOfInt[], int targetValue)
{
    int i = 0, j = n - 1, mid; //penanda rentang data, dan data yang dicari
    int found = 0; //penanda hasil pencarian

    //jika found masih bernilai 0 dan i kurang dari j, maka
    while (found == 0 && i <= j)
    {
        mid = (i + j) / 2; //ambil index tengah dari rentang data 

        //cek data tengah pada rentang data apakah sama dengan data yang ingin dicari
        if (arrOfInt[mid] == targetValue)
        {
            //jika ya maka ubah nilai found
            found = 1;
        }
        else
        {
            //jika tidak, cek nilai data tengah lebih besar dari data yang dicari?
            if (arrOfInt[mid] >= targetValue)
            {
                //jika ya maka penanda rentang data kanan (j)
                //dipindahkan ke posisi data tengah lalu sebelah kirinya
                j = mid - 1;
            }
            else
            {
                //jika tidak maka penanda rentang data kiri (i)
                //dipindahkan ke posisi data tengahh lalu sebelah kanannya
                i = mid + 1;
            }
        }
    }
    return found;
}

int main()
{
    //panggil fungsi lalu cek nilai kembaliannya apakah 0
    if (binarySearch(n, arr, targetValue) == 0)
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

