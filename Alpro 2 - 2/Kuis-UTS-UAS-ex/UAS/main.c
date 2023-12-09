#include "head.h"

int main()
{
    char c;
    int a, b = 0, ans = 0, jumlahkata = 0, d = 0;
    char pita[501], cw[501];
    scanf("%d %c %501[^\n]s", &a, &c, pita); // meminta user untuk mengisi string penting yang akan dipisah
    start(pita);                             // memulai mesin
    temp[jumlahkata][b] = getcc();
    b++;

    while (eop() == 0) // berulang sampai berada pada akhir proses
    {
        adv(pita);
        temp[jumlahkata][b] = getcc(); // pisahkan ke array of string
        b++;
        d++;
        if (b >= a) // reset jika sudah sama dengan a
        {
            b = 0;
            jumlahkata++;
        }
    }
    if (d % a != 0) // jika tidak bisa di mod a, maka -- jumlah kata agar yg tidak a huruf tidak masuk
    {
        jumlahkata--;
    }

    for (int i = 0; i < jumlahkata; i++)
    {
        int j = 0;
        int flag = 0;
        while (j <= a && flag == 0)
        {
            if (temp[i][j] == c) // cek
            {
                ans++;
                flag = 1;
            }
            j++;
        }
    }

    printf("%d\n", ans);
}
