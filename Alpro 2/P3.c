#include <stdio.h>

void tulis(int n)
{
    int counter;
    counter = n;

    if (counter > 0)
    {
        printf("Proses rekursif dengan nilai counter: %d\n", counter);
        counter -= 1;
        tulis(counter);
    }
}

int faktoriallooping(int n)
{
    int i, hasil = 1;
    for (i = 2; i <= n; i++)
    {
        hasil *= i;
    }
    return hasil;
}

int faktorialrekursif(int n)
{
    printf("n = %d\n", n);
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return (n * faktorialrekursif(n - 1));
    }
}

int sumrekursif(int n)
{
    printf("n = %d\n", n);
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n + sumrekursif(n - 1));
    }
}

int carifpb(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        int temp = a % b;
        return carifpb(b, temp);
    }
}

int power(int x, int y)
{
    int hasil;

    if (y == 0)
    {
        return 1;
    }
    else
    {
        hasil = x * power(x, y - 1);
        return hasil;
    }
}
//fibbonaci bottom up
void fib(int *arr, int n, int i)
{
    if (i == 0)
    {
        arr[i] = 0;
        fib(arr, n, i + 1);
    }
    else if (i == 1)
    {
        arr[i] = 1;
        fib(arr, n, i + 1);
    }
    else
    {
        if (i < n)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
            fib(arr, n, i + 1);
        }
    }
}

//fibbonaci top down
int fib2(int* arr, int n)
{
    if (n < 2)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        arr[n] = fib2(arr, n - 1) + fib2(arr, n - 2);
        return arr[n];
    }
}


int main()
{
    //contoh rekursif
    tulis(10);
    printf("\n");

    //faktorial looping
    int hasillooping = faktoriallooping(3);
    printf("hasil faktorial looping 3: %d\n\n", hasillooping);

    //faktorial rekursif
    int hasilrekursif = faktorialrekursif(3);
    printf("hasil faktorial rekursif 3: %d\n\n", hasilrekursif);

    //sum rekursif
    int hasilsumrekursif = sumrekursif(3);
    printf("hasil sum rekursif 3: %d\n\n", hasilsumrekursif);

    //mencari fpb
    int hasilfpb = carifpb(18, 12);
    printf("hasil FPB dari 18 dan 12: %d\n\n", hasilfpb);

    //power rekursif
    int hasilpower = power(2, 3);
    printf("hasil 2 pangkat 3: %d\n\n", hasilpower);

    //fibbonaci bottom up
    int bilfibup;
    printf("masukkan bilangan fibbonaci\n");
    scanf("%d", &bilfibup);
    int arrfibup[bilfibup];

    fib(arrfibup, bilfibup, 0);
    for (int i = 0; i < bilfibup; i++)
    {
        printf("%d ", arrfibup[i]);
    }
    printf("\n");
    
    //fibbonaci top down
    int bilfibtd;
    printf("masukkan bilangan fibbonaci\n");
    scanf("%d", &bilfibtd);
    int arrfibtd[bilfibtd];

    fib(arrfibtd, bilfibtd, 0);
    for (int i = 0; i < bilfibtd; i++)
    {
        printf("%d ", arrfibtd[i]);
    }
    printf("\n");
    return 0;
}