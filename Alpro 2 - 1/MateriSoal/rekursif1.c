#include <stdio.h>
/*
//ex rekursif
void tulis (int n)
{
    int counter;
    counter = n;

    if (counter > 0)
    {
        printf("proses rekursif dengan nilai counter: %d\n", counter);
        counter = counter -1;
        tulis(counter);
    }
}

int main()
{
    tulis(10);
    return 0;
}
*/
/*
//faktorial looping
int faktorial (int n)
{
    printf("n = %d\n", n);
    if((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return (n * faktorial(n-1));
    }
}

int main()
{
    int hasil = faktorial(3);
    printf("hasil faktorial: %d\n", hasil);
    return 0;
}
*/
/*
//penjumlahan(sum)rekursif
int sum (int n)
{
    printf("n = %d\n", n);
    //jika 0?
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * sum(n-1));
    }
}

int main()
{
    int hasil = sum(3);
    printf("hasil sum: %d\n", hasil);
    return 0;
}
*/
/*
//FPB rekursif
int cariFPB(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        int temp = a % b;
        return cariFPB(b, temp);
    }
}

int main()
{
    int hasil = cariFPB(18, 12);
    printf("hasil FPB: %d\n", hasil);
    return 0;
}
*/
/*
//pangkat (power) rekursif
int power (int x, int y)
{
    int hasil;
    if(y == 0)
        return 1;
    else
        hasil = x * power(x, y-1);
    return hasil;
}

int main()
{
    int hasil = power(2, 3);
    printf("hasil pangkat: %d\n", hasil);
    return 0;
}
*/
/*
//fibbonaci bottom up rekursif(1)
void fib(int * arr, int n, int i) //bottom up
{
    if(i == 0)
    {
        arr[i] = 0;
        fib(arr, n, i+1);
    }
    else if (i == 1)
    {
        arr[i] = 1;
        fib(arr, n, i+1);
    }
    else
    {
        if(i  < n)
        {
            arr[i] = arr[i-1] + arr[i - 2];
            fib(arr, n, i+1);
        }
    }
}

int main()
{
    int n;
    printf("masukkan bilangan fibonaci ");
    scanf("%d", &n);
    int arr[n];

    fib(arr, n, 0);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
*/
/*
//fibbonaci top down rekursif
int fib2(int * arr, int n)
{
    int r;
    if(n < 2)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        arr[n] = fib2(arr, r-1) + fib2(arr, n-2);
        return arr[n];
    }
}

int main()
{
    int n;
    printf("masukkan bilangan fibbonaci ");
    scanf("%d", &n);
    int arr[n];

    fib2(arr, n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
*/
/*
//menara hanoi rekursif
void tower(int n, char awal, char akhir, char antara)
{
    if(n == 1)
    {
        printf("pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
    }
    else
    {
        tower((n - 1), awal, antara, akhir);
        //memindahkan piringan berikutnya dari awal ke antara
        printf("pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
        tower((n - 1), antara, akhir, awal);
        //memindahkan piringan berikutnya dari antar akhir
    }
}
int main()
{
    tower(3, 'A', 'C', 'B');
    return 0;
}
*/

//dynamic prgramming(kasus koin - cari banyaknya koih penukar paling sedikit)
int main()
{
    int nilai; //nilai uang yang ditukar
    int n; //banyaknya jenis koin
    int i;

    scanf("%d", &nilai);
    scanf("%d", &n);
    int tukar[n]; //array menyimpan nilai koin penukar
    int memo[nilai + 1]; // memo penyimpan banyaknya koin penukar 

    //memasukkan nilai koin penukar
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tukar[i]);
    }
    //inisialisasi semua sel memo
    for (i = 0; i < nilai; i++)
    {
        memo[i] = -1;
    }
    //tampilkan jumlah koin penukar 
    printf("%d\n", coin(tukar, n, memo, nilai));
    
    return 0;
}