#include "header.h"
int main()
{
    int a, b, c;       // deklarasi var untuk 3 macam data
    char type[3];      // ini untuk type sortnya
    scanf("%s", type); // scan
    scanf("%d", &a);   // scan data pertama
    data gizi[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%s %d %d %d", gizi[i].str, &gizi[i].kalori, &gizi[i].lemak, &gizi[i].harga);       // ini scan nama kalori harga lemak
        gizi[i].supplier = 1;                                                                     // tandain ininya biar nanti pas diprint ada
        gizi[i].hasil = (double)gizi[i].harga / ((double)gizi[i].lemak + (double)gizi[i].kalori); // ini untuk print nilai
        gizi[i].hasil2 = gizi[i].harga / (gizi[i].lemak + gizi[i].kalori);                        // ini untuk dibandingkan karena nanti printnya bisa berbentuk int kalo bulat
    }
    scanf("%d", &b); // ini juga sama kaya yang a
    data gizi2[b];
    for (int i = 0; i < b; i++)
    {
        scanf("%s %d %d %d", gizi2[i].str, &gizi2[i].kalori, &gizi2[i].lemak, &gizi2[i].harga);
        gizi2[i].supplier = 2; // suplier 2
        gizi2[i].hasil = (double)gizi2[i].harga / (gizi2[i].lemak + gizi2[i].kalori);
        gizi2[i].hasil2 = gizi[i].harga / ((double)gizi2[i].lemak + (double)gizi2[i].kalori);
    }
    scanf("%d", &c); // ini juga sama kaya yang a
    data gizi3[c];
    for (int i = 0; i < c; i++)
    {
        scanf("%s %d %d %d", gizi3[i].str, &gizi3[i].kalori, &gizi3[i].lemak, &gizi3[i].harga);
        gizi3[i].supplier = 3; // supplier 3
        gizi3[i].hasil = (double)gizi3[i].harga / (gizi3[i].lemak + gizi3[i].kalori);
        gizi3[i].hasil2 = gizi3[i].harga / (gizi3[i].lemak + gizi3[i].kalori);
    }
    if (strcmp(type, "qs") == 0) // lalu jika tipenya quick, panggil prosedur quick
    {
        qsorting(0, a - 1, gizi);
        qsorting(0, b - 1, gizi2);
        qsorting(0, c - 1, gizi3);
    }
    else // jika bukan quick, panggil prosedur sorting, quick dipisah karena ada rekursif
    {
        sorting(a, gizi, type);
        sorting(b, gizi2, type);
        sorting(c, gizi3, type);
    }
    data merge1[a + b], result[a + b + c];  // deklarasi var untuk menyimpan merge
    merge(gizi, gizi2, merge1, a, b);       // lalu merge gizi 1 dan 2
    merge(merge1, gizi3, result, a + b, c); // merge hasil gizi 1,2 dengan 3
    printf("Per Supplier:\nSupplier 1:\n"); // print
    for (int i = 0; i < a; i++)
    {
        printf("%s %d %d %d - ", gizi[i].str, gizi[i].kalori, gizi[i].lemak, gizi[i].harga); // print kalori lemak harga nama
        if (gizi[i].hasil == gizi[i].hasil2)                                                 // jika sama, artinya bulat, maka print integer, 250,00=250
        {
            printf("%d\n", gizi[i].hasil2);
        }
        else // jika tidak sama, maka print double
        {
            printf("%0.2lf\n", gizi[i].hasil);
        }
    }
    printf("\nSupplier 2:\n"); // yg ini sama dengan yang supplier 1
    for (int i = 0; i < b; i++)
    {
        printf("%s %d %d %d - ", gizi2[i].str, gizi2[i].kalori, gizi2[i].lemak, gizi2[i].harga); // print nama kalori lemak harga
        if (gizi2[i].hasil == gizi2[i].hasil2)                                                   // bandingkan
        {
            printf("%d\n", gizi2[i].hasil2); // print integer jika sama, integer yg dihitung di awal tadi
        }
        else // jika tidak sama print double
        {
            printf("%0.2lf\n", gizi2[i].hasil);
        }
    }
    printf("\nSupplier 3:\n"); // supplier 3 juga sama dengan yang tadi
    for (int i = 0; i < c; i++)
    {
        printf("%s %d %d %d - ", gizi3[i].str, gizi3[i].kalori, gizi3[i].lemak, gizi3[i].harga); // print nama kalori lemak harga
        if (gizi3[i].hasil == gizi3[i].hasil2)                                                   // print ini jika sama `
        {
            printf("%d\n", gizi3[i].hasil2);
        }
        else // jika beda, print double
        {
            printf("%0.2lf\n", gizi3[i].hasil);
        }
    }
    printf("\nSemua:\n"); // print semua
    for (int i = 0; i < a + b + c; i++)
    {
        printf("%s %d %d %d - ", result[i].str, result[i].kalori, result[i].lemak, result[i].harga); // print nama kalori lemak harga
        if (result[i].hasil == result[i].hasil2)                                                     // bandingkan
        {
            printf("%d", result[i].hasil2); // jika sama print integer
        }
        else
        {
            printf("%0.2lf", result[i].hasil); // jika tidak, print double
        }
        printf(" Supplier %d\n", result[i].supplier); // print supplier yang tadi kita simpan
    }

    return 0;
}
