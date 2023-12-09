#include <stdio.h>
#include <string.h>


// struct untuk mendefinisikan properti dari sebuah laptop
typedef struct
{
    int id;
    char merk[20];
    char nama[50];
    float cpuSpeed;
    int ramSpeed;
    char gpuName[50];
} spesifikasiLaptop;


int main()
{
    int n = 0; // counter untuk jumlah data, khususnya data laptop


    spesifikasiLaptop laptop[50]; // data laptop max 50


    FILE *fLaptop;                          // pointer untuk file yang akan dibuka
    fLaptop = fopen("listLaptop.dat", "r"); // buka file dengan mode read
    fscanf(fLaptop, "%d %s %s %f %d %s", // scan 6 data pertama (baris 1)
           &laptop[n].id, laptop[n].merk, laptop[n].nama,
           &laptop[n].cpuSpeed, &laptop[n].ramSpeed, laptop[n].gpuName);


    // cek kolom id yang baru discan tadi apakah sama dengan -1?
    if (laptop[n].id == -1)
    {
        // jika ya maka data yang tadi discan merupakan EOF
        printf("File Kosong");
    }
    else
    {
        // kalau tidak, berarti bukan EOF


        // ketika kolom nama bukan EOF lakukan:
        while (strcmp(laptop[n].nama, "####") != 0)
        {
             n++; // maju ke penampung data berikutnya
           fscanf(fLaptop, "%d %s %s %f %d %s", // scan 6 data berikutnya (baris 2 dan seterusnya)
                   &laptop[n].id, laptop[n].merk, laptop[n].nama,
                   &laptop[n].cpuSpeed, &laptop[n].ramSpeed, laptop[n].gpuName);
        }


        // tampilkan ke layar hasil readnya
        printf("Data Laptop : %d\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d %s %s %.2f %d %s\n",
                   laptop[i].id, laptop[i].merk, laptop[i].nama,
                   laptop[i].cpuSpeed, laptop[i].ramSpeed, laptop[i].gpuName);
        }
    }


    // "tutup file"
    fclose(fLaptop);


    return 0;
}
