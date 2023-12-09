#include "head.h"

void scandata(data menu[], int n, int jmlmenu, int jmlgula, int jmlkarbo, int jmlprotein)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d",&menu[i].nama, menu[i].gula, menu[i].karbo, menu[i].protein);
        jmlgula += menu[i].gula;
        jmlkarbo += menu[i].karbo;
        jmlprotein += menu[i].protein;
        menu[i].hasil = menu[i].gula + menu[i].protein + menu[i].karbo;
    }
    jmlmenu = jmlgula + jmlkarbo + jmlprotein;
}

void swap(data *a, data *b)
{
    data temp; 
    temp = *a; 
    *a = *b;   
    *b = temp; 
}
void sorting(data menu[], int n, char tipe[])
{
    if (strcmp(tipe, "insert") == 0)
    {
    
    }
    else if (strcmp(tipe, "select") == 0)
    {

    }
    else if (strcmp(tipe, "bubble") == 0)
    {

    }
}
void qsorting(data menu[], int n)
{

}

void merge(data temp1[], int n1, data temp2[], int n2, data temp3[])
{
    int i1 = 0, i2 = 0, i3 = 0;

    while ((i1 < n1) && (i2 < n2))
    {
        if (temp1[i1].hasil > temp2[i2].hasil)
        {
            strcpy(temp3[i3].nama, temp1[i1].nama);
            temp3[i3].gula = temp1[i1].gula;
            temp3[i3].karbo = temp1[i1].karbo;
            temp3[i3].protein = temp1[i1].protein;
            temp3[i3].hasil = temp1[i1].hasil;
            i3++;
            i1++;
        }
        else
        {
            strcpy(temp3[i3].nama, temp2[i2].nama);
            temp3[i3].gula = temp1[i2].gula;
            temp3[i3].karbo = temp1[i2].karbo;
            temp3[i3].protein = temp1[i2].protein;
            temp3[i3].hasil = temp1[i2].hasil;
            i3++;
            i2++;
        }
    }
    while (i1 < n1)
    {
        strcpy(temp3[i3].nama, temp1[i1].nama);
        temp3[i3].gula = temp1[i1].gula;
        temp3[i3].karbo = temp1[i1].karbo;
        temp3[i3].protein = temp1[i1].protein;
        temp3[i3].hasil = temp1[i1].hasil;
        i3++;
        i1++;
    }
    while (i2 < n2)
    {
        strcpy(temp3[i3].nama, temp2[i2].nama);
        temp3[i3].gula = temp1[i2].gula;
        temp3[i3].karbo = temp1[i2].karbo;
        temp3[i3].protein = temp1[i2].protein;
        temp3[i3].hasil = temp1[i2].hasil;
        i3++;
        i2++;
    }
    
}

void print(int n, data menu[])
{
    printf("menu buka puasa: \n");
    for (int i = 0; i < n; i++)
    {
        print("%s gula-%d karbo-%d protein-%d total-%d\n", menu[i].nama, menu[i].gula, menu[i].protein, menu[i].total);
    }
    printf("jumlah berat total menu: %d\n", jmlmenu1 + jmlmenu2 + jmlmenu3);
    printf("jumlah berat total gula: %d\n", jmlgula1 + jmlgula2 + jmlgula3);
    printf("jumlah berat total karbo: %d\n", jmlkarbo1 + jmlkarbo2 + jmlkarbo3);
    printf("jumlah berat total protein: %d\n", jmlprotein1 + jmlprotein2 + jmlprotein3);
    
}
