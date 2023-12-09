#include "head.h"

int main()
{
    int n;
    scanf("%d", &n);

    data motor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &motor[i].kodeMotor);
        scanf("%s", &motor[i].merkMotor);
        scanf("%s", &motor[i].tipeMotor);
        scanf("%s", &motor[i].jmlTerjual);
        scanf("%llu", &motor[i].hargaMotor);
        motor[i].penjualan = motor[i].jmlTerjual * motor[i].hargaMotor;
    }

    char urut[10];
    scanf("%s", urut);

    long long int cari;
    scanf("%llu", &cari);

    sorting(motor, n, urut);
    search(motor, n, cari, urut);

    printf("terendah:\n\n");

    printf("tertinggi:\n");
    return 0;
}