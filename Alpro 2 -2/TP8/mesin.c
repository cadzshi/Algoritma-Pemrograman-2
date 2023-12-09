#include "head.h"
//prosedur mengisi list laptop
void fscanf_laptop(FILE* f, char s[], laptop a[])   
{
    f = fopen(s, "r");  
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s %s %s", a[i].listLaptop, a[i].processor, a[i].merk, a[i].ram); 
        if (strcmp(a[i].listLaptop, "####") == 0) 
        {
            dummy = 1;
        } 
        else 
        {
            i++;
        }
    }
    while (dummy == 0);
    n_listLaptop = i;    
    fclose(f);  
}
//prosedur mengisi spesifikasi laptop
void fscanf_data(FILE* f, char s[], data a[], int* n)   
{
    f = fopen(s, "r");
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s", a[i].id, a[i].nama); 
        if (strcmp(a[i].id, "####") == 0) 
        {
            dummy = 1;
        }
        else 
        {
            i++;
        }
    }
    while (dummy == 0);
    *n = i; 
    fclose(f);
}
//prosedur mengubah isi file list laptop
void fprintf_laptop(FILE* f, char s[], laptop a[])  
{
    f = fopen(s, "w");  
    for (int i = 0; i < n_listLaptop; i++)
    {
        fprintf(f, "%s %s %s %s\n", a[i].listLaptop, a[i].processor, a[i].merk, a[i].ram);  
    }
    fprintf(f, "#### #### #### ####");  
    fclose(f); 
}
//prosedur mengubah isi file spesifikasi laptop
void fprintf_data(FILE* f, char s[], data a[], int n)   
{
    f = fopen(s, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %s\n", a[i].id, a[i].nama);  
    }
    fprintf(f, "#### ####");
    fclose(f);
}
//prosedur menampilkan record list laptop
void printf_laptop(laptop a[])  
{
    int longest_l = 10, longest_p = 9, longest_m = 4, longest_r = 3;
    for (int i = 0; i < n_listLaptop; i++) 
    {
        if (strlen(a[i].listLaptop) > longest_l) 
        {
            longest_l = strlen(a[i].listLaptop);
        }
        if (strlen(a[i].processor) > longest_p) 
        {
            longest_p = strlen(a[i].processor);
        }
        if (strlen(a[i].merk) > longest_m) 
        {
            longest_m = strlen(a[i].merk);
        }
        if (strlen(a[i].ram) > longest_r) 
        {
            longest_r = strlen(a[i].ram);
        }
    }
    
    garis_tabel(longest_l, longest_p, longest_m, longest_r); 
    
    printf("| ListLaptop");
    for (int i = 0; i < longest_l - 10; i++)
    {
        printf(" ");
    }
    printf(" | Processor");
    for (int i = 0; i < longest_p - 9; i++) 
    {
        printf(" ");
    }
    printf(" | Merk");
    for (int i = 0; i < longest_m - 4; i++) 
    {
        printf(" ");
    }
    printf(" | Ram");
    for (int i = 0; i < longest_r - 3; i++) 
    {
        printf(" ");
    }
    printf(" |\n");
    garis_tabel(longest_l, longest_p, longest_m, longest_r);
    // print isi tabel
    for (int i = 0; i < n_listLaptop; i++)
    {
        printf("| %s", a[i].listLaptop); 
        for (int j = 0; j < longest_l - strlen(a[i].listLaptop); j++) 
        {
            printf(" ");
        }   
        printf(" | %s", a[i].processor);    
        for (int j = 0; j < longest_p - strlen(a[i].processor); j++) 
        {
            printf(" ");
        } 
        printf(" | %s", a[i].merk);
        for (int j = 0; j < longest_m - strlen(a[i].merk); j++) 
        {
            printf(" ");
        } 
        printf(" | %s", a[i].ram);
        for (int j = 0; j < longest_r - strlen(a[i].ram); j++) 
        {
            printf(" ");
        } 
        printf(" |\n");
    }
    garis_tabel(longest_l, longest_p, longest_m, longest_r);
    printf("\nMasukkan karakter apapun untuk kembali ke menu utama : ");
    scanf("%s");    // scanf kosong agar program tidak langsung kembali ke menu utama atau keluar
    menuUtama();
}
//prosedur garis tabel
void garis_tabel(int l, int p, int m, int r) 
{
    printf("+-");
    for (int i = 0; i < l; i++) 
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < p; i++) 
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < m; i++) 
    {
        printf("-");
    }
    printf("-+-");
    for (int i = 0; i < r; i++) 
    {
        printf("-");
    }
    printf("-+\n");
}
//prosedur menampilkan record spesifikasi laptop
void printf_data(data a[], int n)   
{
    int longest = 4;
    for (int i = 0; i < n; i++)
    {
        if (strlen(a[i].nama) > longest) 
        {
            longest = strlen(a[i].nama);
        }
    }
    garis_tabel2(longest);
    printf("| ID   | Nama");
    for (int i = 0; i < longest - 4; i++) 
    {
        printf(" ");
    }
    printf(" |\n");
    garis_tabel2(longest);
    for (int i = 0; i < n; i++)
    {
        printf("| %s | %s", a[i].id, a[i].nama);
        for (int j = 0; j < longest - strlen(a[i].nama); j++) 
        {
            printf(" ");
        }
        printf(" |\n");
    }
    garis_tabel2(longest);
    printf("\nMasukkan karakter apapun untuk kembali ke menu utama : ");
    scanf("%s");
    menuUtama();
}
//prosedur buat tabel juga
void garis_tabel2(int q)  
{
    printf("+------+-");
    for (int i = 0; i < q; i++) 
    {
        printf("-");
    }
    printf("-+\n");
}
//prosedur insert list laptop
void insertLaptop()  
{
    system("cls");
    laptop baru;
    printf("Insert record List Laptop\n\n");
    
    printf("Masukkan List Laptop baru       : ");
    scanf("%s", baru.listLaptop);
    printf("Masukkan ID Processor Laptop    : ");
    scanf("%s", baru.processor);
    printf("Masukkan ID Merk Laptop         : ");
    scanf("%s", baru.merk);
    printf("Masukkan ID RAM Laptop          : ");
    scanf("%s", baru.ram);
    printf("\nRecord List Laptop baru berhasil ditambahkan\n\n"); 
    a_listLaptop[n_listLaptop] = baru;   
    n_listLaptop++;  
    fprintf_laptop(f_listLaptop, "data/listLaptop.dat", a_listLaptop);
    printf_laptop(a_listLaptop);   
}
//prosedur insert spesifikasi laptopnya
void insertData(data a[], int* n, char c)  
{
    system("cls");
    char kategori[3][10] = {"processor", "merk", "ram"};   
    data baru;
    printf("Insert record %s\n\n", kategori[c - 50]);
    printf("Masukkan ID %s baru   : ", kategori[c - 50]);
    scanf("%s", baru.id);
    printf("Masukkan nama %s baru : ", kategori[c - 50]);
    scanf("%s", baru.nama);
    printf("\nRecord %s baru berhasil ditambahkan\n\n", kategori[c - 50]);
    
    int i = *n - 1; 
    while (strcmp(baru.id, a[i].id) < 0 && i >= 0)  
    {
        a[i + 1] = a[i]; 
        i--;    
    }
    a[i + 1] = baru;   
    *n += 1;    
    
    if (c == '2') 
    {
        fprintf_data(f_processor, "data/Processor.dat", a, *n);
    }
    else if (c == '3') 
    {
        fprintf_data(f_merk, "data/Merk.dat", a, *n);
    }
    else
    {
        fprintf_data(f_ram, "data/Ram.dat", a, *n);
    }
    printf_data(a, *n); 
}
//prosedur menu
void menuUtama()
{
    system("cls");
    printf("+----------------------------+\n");
    printf("|         Menu Utama         |\n");
    printf("+----+-----------------------+\n");
    printf("| No | Deskripsi             |\n");
    printf("+----+-----------------------+\n");
    printf("| 1  | Tampilkan records     |\n");
    printf("| 2  | Insert records        |\n");
    printf("| 0  | Tutup program         |\n");
    printf("+----+-----------------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    if (pilihan == '0') 
    {
        return;
    }
    else if (pilihan == '1') 
    {
        menuPrint();
    }
    else if (pilihan == '2') 
    {
        menuInsert();
    }
    else 
    {
        menuUtama();
    }
}

void menuPrint()
{
    system("cls");
    printf("+----------------------+\n");
    printf("|  Tampilkan  records  |\n");
    printf("+----+-----------------+\n");
    printf("| No | Deskripsi       |\n");
    printf("+----+-----------------+\n");
    printf("| 1  | List Laptop     |\n");
    printf("| 2  | Processor       |\n");
    printf("| 3  | Merk            |\n");
    printf("| 4  | Ram             |\n");
    printf("| 0  | Menu sebelumnya |\n");
    printf("+----+-----------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    system("cls");

    if (pilihan == '0') 
    {
        menuUtama();
    }
    else if (pilihan == '1') 
    {
        printf_laptop(a_listLaptop);
    }
    else if (pilihan == '2') 
    {
        printf_data(a_processor, n_processor);
    }
    else if (pilihan == '3') 
    {
        printf_data(a_merk, n_merk);
    }
    else if (pilihan == '4') 
    {
        printf_data(a_ram, n_ram);
    }
    else
    {
        menuPrint();
    }
}

void menuInsert()
{
    system("cls");
    printf("+----------------------+\n");
    printf("|    Insert  record    |\n");
    printf("+----+-----------------+\n");
    printf("| No | Deskripsi       |\n");
    printf("+----+-----------------+\n");
    printf("| 1  | List Laptop     |\n");
    printf("| 2  | Processor       |\n");
    printf("| 3  | Merk            |\n");
    printf("| 4  | Ram             |\n");
    printf("| 0  | Menu sebelumnya |\n");
    printf("+----+-----------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    if (pilihan == '0') 
    {
        menuUtama();
    }
    else if (pilihan == '1') 
    {
        insertLaptop();
    }
    else if (pilihan == '2') 
    {
        insertData(a_processor, &n_processor, pilihan);
    }
    else if (pilihan == '3')  
    {
        insertData(a_merk, &n_merk, pilihan);
    }
    else if (pilihan == '4') 
    {
        insertData(a_ram, &n_ram, pilihan);
    }
    else 
    {
        menuInsert();
    }
}

void init()
{
    fscanf_laptop(f_listLaptop, "data/listLaptop.dat", a_listLaptop);
    fscanf_data(f_processor, "data/Processor.dat", a_processor, &n_processor);
    fscanf_data(f_merk, "data/Merk.dat", a_merk, &n_merk);
    fscanf_data(f_ram, "data/Ram.dat", a_ram, &n_ram);
    
    menuUtama();
}