#include "head.h"

void proses()  
{
    f_mhsfinal = fopen("data/mhsfinal.dat", "w");    // buka puasa
    for (int i = 0; i < n_mhs; i++)
    {
        data m = binary_search(a_mhs, 0, n_mhs - 1, a_mhs[i].nama);  
        data j = binary_search(a_jurusan, 0, n_jurusan - 1, a_mhs[i].jurusan);  
        data f = binary_search(a_fakultas, 0, n_fakultas - 1, a_mhs[i].fakultas);   
        fprintf(f_mhsfinal, "%s %s %s %s\n", a_mhs[i].nama, m.nama, j.nama, f.nama);  
    }
    fprintf(f_mhsfinal, "#### #### ####");  
    fclose(f_mhsfinal);  
    fscanf_mhs(f_mhsfinal, "data/mhsfinal.dat", a_mhsfinal); 
}

data binary_search(data a[], int l, int r, char s[])   
{
    if (l <= r) 
    {
        int m = (l + r) / 2;   
        
        if (strcmp(a[m].id, s) < 0) 
        {
            return binary_search(a, m + 1, r, s);
        }
        if (strcmp(a[m].id, s) > 0) 
        {
            return binary_search(a, l, m - 1, s);
        }
        return a[m];   
    }
    data temp;
    strcpy(temp.id, s);
    strcpy(temp.nama, "????");  
    return temp;
}

void printmhs(mhs a[])
{
    for (int i = 0; i < n_mhs; i++)
    {
        printf("%s", a[i].nama); 
        printf("%s", a[i].jurusan);   
        printf("%s", a[i].fakultas);  
    }
}

void fscanf_mhs(FILE* f, char s[], mhs a[])   
{
    f = fopen(s, "r");  // buka file
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s %s", a[i].nama, a[i].jurusan, a[i].fakultas); 
        if (strcmp(a[i].nama, "####") == 0) dummy = 1; 
        else i++;
    }
    while (dummy == 0);
    n_mhs = i;    
    fclose(f); 
}

void fscanf_data(FILE* f, char s[], data a[], int* n)   
{
    
    f = fopen(s, "r");
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s", a[i].id, a[i].nama); 
        if (strcmp(a[i].id, "####") == 0) dummy = 1;
        else i++;
    }
    while (dummy == 0);
    *n = i;
    fclose(f);
}

void init()
{

    fscanf_mhs(f_mhs, "data/mahasiswa.txt", a_mhs);
    fscanf_data(f_fakultas, "data/fakultas.dat", a_fakultas, &n_fakultas);
    fscanf_data(f_jurusan, "data/jurusan.dat", a_jurusan, &n_jurusan);
    proses();
    printmhs(a_mhsfinal);

}