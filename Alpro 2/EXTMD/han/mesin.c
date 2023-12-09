/*
Saya Farhan Muzhaffar Tiras Putra NIM 2105879
mengerjakan Tugas Masa Depan dalam mata kuliah Algoritma dan Pemograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin.
*/

// menggunakan library yang telah dibuat
#include "mesinkata.h"

// definisi prosedur dan fungsi yang telah dibuat

// prosedur untuk membaca kata pertama dalam inputan
void STARTKATA(char pita[])
{
    indeks = 0;                   // indeks dimulai dari 0
    panjangkata = 0;              // panjangkata juga direset
    while ((pita[indeks] == ' ')) // syarat looping, ketika pita pada indeks sekarang adalah spasi
    {
        indeks++; // indeks bertambah 2
    }
    while ((pita[indeks] != ';') && (pita[indeks] != ' ')) // syarat looping, ketika pita pada indeks sekarang bukan merupakan semicolon (;) dan spasi
    {
        ckata[panjangkata] = pita[indeks]; // ckata dengan indeks panjangkata diisi oleh pita indeks ke indeks
        indeks++;                          // indeks bertambah
        panjangkata++;                     // panjangkata bertambah
    }
    ckata[panjangkata] = '\0'; // kata sekarang ditutup oleh null
}

// prosedur untuk membaca kata selanjutnya dari string inputan
void INCKATA(char pita[])
{
    panjangkata = 0;              // panjangkata juga direset
    while ((pita[indeks] == ' ')) // syarat looping, ketika pita pada indeks sekarang adalah spasi
    {
        indeks++; // indeks bertambah
    }
    while ((pita[indeks] != ';') && (pita[indeks] != ' ')) // syarat looping, ketika pita pada indeks sekarang bukan merupakan semicolon (;) dan spasi
    {
        ckata[panjangkata] = pita[indeks]; // ckata dengan indeks panjangkata diisi oleh pita indeks ke indeks
        indeks++;                          // indeks bertambah
        panjangkata++;                     // panjangkata bertambah
    }
    ckata[panjangkata] = '\0'; // kata sekarang ditutup oleh null
}

// untuk mengeluarkan kata sekarang
char *GETKATA()
{
    return ckata; // mengembalikan kata sekarang
}

// untuk mengecek eop yang berupa semicolon(;)
int EOPKATA(char pita[])
{
    if (pita[indeks] == ';') // jika karakter pada pita ke indeks adalah semicolon(;)
    {
        return 1; // mengembalikan nilai 1
    }
    else
    {
        return 0; // mengembalikan nilai 0
    }
}

// untuk menyimpan data inputan berupa id, nama, dan code motor dan/atau nama motor pada variabel
void GETDATA(char input[])
{
    STARTKATA(input); // memulai mesin kata

    int a = 0;
    for (int p = 0; p <= m; p++)
    {
        INCKATA(input); // menaikkan kata selanjutnya
        a++;
    }

    strcpy(ID, GETKATA());      // menyalin id
    INCKATA(input);             // menaikkan kata selanjutnya
    strcpy(data[0], GETKATA()); // menyalin data
    INCKATA(input);             // menaikkan kata selanjutnya
    strcpy(data[1], GETKATA()); // menyalin data
}

// untuk mengeluarkan id dari rider atau motor
char *GETID()
{
    return ID; // mengeluarkan id
}

// untuk mengecek query apa yang harus digunakan pada table riders
int CHECKQUERY(char input[], riders Rdata)
{
    // deklarasi variabel untuk query, indikator dan iterator
    int query = 0;
    int done = 0;
    int i = 0;
    // jika query yang ditulis berjumlah 1
    if (m == 1)
    {

        if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta adalah ENTRI
        {
            if (CHECKDATA(Rdata) == 0) // jika data belum ada di file
            {
                query = 1; // query diisi 1
            }
            else // jika data sudah ada
            {
                // mengeluarkan data yang sama yang ada di file
                printf("DATA IS ALREADY IN THE FILE\n\n");
                printf("Number  ");
                printf("Name  ");
                for (int i = 0; i < strlen(data[0]) - 4; i++)
                {
                    printf(" ");
                }
                printf("Motor\n");
                printf("%s      %s  %s\n\n", GETID(), data[0], data[1]);
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "UBAH") == 0) // jika query yang diminta adalah UBAH
        {
            if (CHECKDATA(Rdata) == 1) // jika data sudah ada di file
            {
                query = 2; // query diisi 2
            }
            else // jika data belum ada di file
            {
                printf("DATA CANNOT BE FOUND\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "HAPUS") == 0) // jika query yang diminta adalah HAPUS
        {
            if (CHECKDATA(Rdata) == 1) // jika data sudah ada di file
            {
                query = 3; // query diisi 3
            }
            else // jika data belum ada di file
            {
                printf("DATA CANNOT BE FOUND\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "TAMPIL") == 0) // jika query yang diminta adalah TAMPIL
        {
            if (CHECKDATA(Rdata) == 1) // jika data sudah ada di file
            {
                query = 4; // query diisi 4
            }
            else // jika data belum ada di file
            {
                printf("DATA CANNOT BE FOUND\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else
        {
            printf("PLEASE INPUT A VALID QUERY!\n\n");
            system("pause"); // tampilan akan dipause
        }
    }
    else if (m == 2) // jika query yang ditulis berjumlah 2
    {
        i = 0;
        while ((done == 0) && (i < m))
        {
            if (strcmp(cquery[i], "ENTRI") == 0)
            {
                if (CHECKDATA(Rdata) == 0) // jika data belum ada di file
                {
                    query = 1; // query diisi 1
                    done = 1;  // done diisi oleh 1
                }
                else // jika data ada di file
                {
                    i++;
                    if (strcmp(cquery[i], "UBAH") == 0)
                    {
                        query = 2; // query diisi 2
                        done = 1;  // done diisi oleh 1
                    }
                    else if (strcmp(cquery[i], "HAPUS") == 0)
                    {
                        query = 3; // query diisi 3
                        done = 1;  // done diisi oleh 1
                    }
                    else if (strcmp(cquery[i], "TAMPIL") == 0)
                    {

                        query = 4; // query diisi 4
                        done = 1;  // done diisi oleh 1
                    }
                    else
                    {
                        printf("DATA IS ALREADY IN THE FILE\n\n");
                        printf("Number  ");
                        printf("Name  ");
                        for (int i = 0; i < strlen(data[0]) - 4; i++)
                        {
                            printf(" ");
                        }
                        printf("Motor\n");
                        printf("%s       %s  %s\n", GETID(), data[0], data[1]);
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "UBAH") == 0)
            {
                if (CHECKDATA(Rdata) == 1) // jika data sudah ada di file
                {
                    query = 2; // query diisi 2
                    done = 1;  // done diisi oleh 1
                }
                else // jika data belum ada di file
                {
                    i++;
                    if (strcmp(cquery[i], "ENTRI") == 0)
                    {
                        query = 1; // query diisi 1
                        done = 1;  // done diisi oleh 1
                    }
                    else
                    {
                        printf("DATA CANNOT BE FOUND\n\n");
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "HAPUS") == 0)
            {
                if (CHECKDATA(Rdata) == 1) // jika data sudah ada di file
                {
                    query = 3; // query diisi 3
                    done = 1;  // done diisi oleh 1
                }
                else // jika data belum ada di file
                {
                    i++;
                    if (strcmp(cquery[i], "ENTRI") == 0)
                    {
                        query = 1; // query diisi 1
                        done = 1;  // done diisi oleh 1
                    }
                    else
                    {
                        printf("DATA CANNOT BE FOUND\n\n");
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "TAMPIL") == 0)
            {

                query = 4; // query diisi 4
                done = 1;  // done diisi oleh 1
            }
            else
            {
                printf("PLEASE INPUT A VALID QUERY!\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
    }
    else if (m >= 3) // jika query yang ditulis berjumlah lebih dari 3
    {
        // variabel untuk iterartor dan indikator
        i = 0;         // i diisi 0
        int found = 0; // found diisi 0
        while ((found == 0) && (i < m))
        {
            if (strcmp(cquery[i], "ENTRI") == 0) // jika ada query ENTRI
            {
                found = 1; // found diisi oleh 1
            }
            i++; // i bertambah
        }
        if (found == 1) // jika foundnya 1
        {
            if (CHECKDATA(Rdata) == 0) // jika datanya belum ada
            {
                query = 1; // query diisi 1
                done = 1;  // done diisi oleh 1
            }
            else // jika data sudah ada
            {
                // menampilkan data yang sama pada file
                printf("DATA IS ALREADY IN THE FILE\n\n");
                printf("Number  ");
                printf("Name  ");
                for (int i = 0; i < strlen(data[0]) - 4; i++)
                {
                    printf(" ");
                }
                printf("Motor\n");
                printf("%s       %s  %s\n", GETID(), data[0], data[1]);
                printf("PLEASE INPUT A VALID QUERY\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else
        {
            // meminta untuk meninput query yang valid
            printf("PLEASE INPUT A VALID QUERY\n\n");
            system("pause"); // tampilan akan dipause
        }
    }
    return query; // mengembalikan nilai variabel query
}

// untuk mengecek query apa yang harus digunakan pada table motors
int CHECKQUERYMOTOR(char input[], motors Rdata)
{
    // deklarasi variabel untuk query, indikator dan iterator
    int query = 0;
    int done = 0;
    int i = 0;
    // jika jumlah query yang ditulis cuma 1
    if (m == 1)
    {
        if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
        {
            if (CHECKDATAMOTORS(Rdata) == 0) // jika data tidak ada pada file
            {
                query = 1; // query diisi 1
            }
            else
            {
                // menampilkan data yang sudah ada
                printf("DATA IS ALREADY IN THE FILE\n\n");
                printf("Code Motor  ");
                printf("Motor\n");
                printf("%s", GETID());
                for (int j = 0; j < 10; j++)
                {
                    printf(" ");
                }
                printf("%s\n\n", data[0]);
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "UBAH") == 0) // jika query yang diminta dalah UBAH
        {
            if (CHECKDATAMOTORS(Rdata) == 1) // jika data ada pada file
            {
                query = 2; // query diisi 2
            }
            else
            {
                printf("DATA CANNOT BE FOUND\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "HAPUS") == 0) // jika query yang diminta dalah HAPUS
        {
            if (CHECKDATAMOTORS(Rdata) == 1) // jika data ada pada file
            {
                query = 3; // query diisi 3
            }
            else
            {
                printf("DATA CANNOT BE FOUND\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else if (strcmp(cquery[i], "TAMPIL") == 0) // jika query yang diminta dalah TAMPIL
        {

            query = 4; // query diisi 4
        }
        else
        {
            printf("PLEASE INPUT A VALID QUERY!\n\n");
            system("pause"); // tampilan akan dipause
        }
    }
    // jika jumlah query yang ditulis 2
    else if (m == 2)
    {
        i = 0;
        while ((done == 0) && (i < m))
        {
            if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
            {
                if (CHECKDATAMOTORS(Rdata) == 0) // jika data tidak ada pada file
                {
                    query = 1; // query diisi 1
                    done = 1;  // done diisi 1
                }
                else
                {
                    i++;
                    if (strcmp(cquery[i], "UBAH") == 0) // jika query yang diminta dalah UBAH
                    {
                        query = 2; // query diisi 2
                        done = 1;  // done diisi 1
                    }
                    else if (strcmp(cquery[i], "HAPUS") == 0) // jika query yang diminta dalah HAPUS
                    {
                        query = 3; // query diisi 3
                        done = 1;  // done diisi 1
                    }
                    else if (strcmp(cquery[i], "TAMPIL") == 0) // jika query yang diminta dalah TAMPIL
                    {
                        query = 4; // query diisi 4
                        done = 1;  // done diisi 1
                    }
                    else
                    {
                        // menampilkan data yang sudah ada
                        printf("DATA IS ALREADY IN THE FILE\n\n");
                        printf("Code Motor  ");
                        printf("Motor\n");
                        printf("%s", GETID());
                        for (int j = 0; j < 10; j++)
                        {
                            printf(" ");
                        }
                        printf("%s\n\n", data[0]);
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "UBAH") == 0) // jika query yang diminta dalah ENTRI
            {
                if (CHECKDATAMOTORS(Rdata) == 1) // jika data ada pada file
                {
                    query = 2; // query diisi 2
                    done = 1;  // done diisi 1
                }
                else
                {
                    i++;
                    if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
                    {
                        query = 1; // query diisi 1
                        done = 1;  // done diisi 1
                    }
                    else
                    {
                        printf("DATA CANNOT BE FOUND\n\n");
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "HAPUS") == 0) // jika query yang diminta dalah HAPUS
            {
                if (CHECKDATAMOTORS(Rdata) == 1) // jika data ada pada file
                {
                    query = 3; // query diisi 3
                    done = 1;  // done diisi 1
                }
                else
                {
                    i++;
                    if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
                    {
                        query = 1; // query diisi 1
                        done = 1;  // done diisi 1
                    }
                    else
                    {
                        printf("DATA CANNOT BE FOUND\n\n");
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else if (strcmp(cquery[i], "TAMPIL") == 0) // jika query yang diminta dalah TAMPIL
            {
                if (CHECKDATAMOTORS(Rdata) == 1) // jika data ada pada file
                {
                    query = 4; // query diisi 4
                    done = 1;  // done diisi 1
                }
                else
                {
                    i++;
                    if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
                    {
                        query = 1; // query diisi 1
                        done = 1;  // done diisi 1
                    }
                    else
                    {
                        printf("DATA CANNOT BE FOUND\n\n");
                        system("pause"); // tampilan akan dipause
                    }
                }
            }
            else
            {
                printf("PLEASE INPUT A VALID QUERY!\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
    }
    else if (m >= 3)
    {
        // deklarasi iterator dan indikator
        i = 0;                          // i diisi 0
        int found = 0;                  // found diisi 0
        while ((found == 0) && (i < m)) // syarat looping
        {
            if (strcmp(cquery[i], "ENTRI") == 0) // jika query yang diminta dalah ENTRI
            {
                found = 1; // found diisi 1
            }
            i++; // i bertambah
        }

        if (found == 1) // jika found adalah 1
        {
            if (CHECKDATAMOTORS(Rdata) == 0) // jika data tidak ada
            {
                query = 1; // query diisi 1
                done = 1;  // done diisi 1
            }
            else
            {
                // menampilkan data yang sudah ada
                printf("DATA IS ALREADY IN THE FILE\n");
                printf("Code Motor  ");
                printf("Motor\n");
                printf("%s", GETID());
                for (int j = 0; j < 10; j++)
                {
                    printf(" ");
                }
                printf("%s\n\n", data[0]);
                printf("PLEASE INPUT A VALID QUERY\n\n");
                system("pause"); // tampilan akan dipause
            }
        }
        else
        {
            printf("PLEASE INPUT A VALID QUERY\n");
            system("pause"); // tampilan akan dipause
        }
    }

    return query; // mengenmalikan nilai pada variabel query
}

// untuk mengecek eop
int CHECKEOP(char input[])
{
    // deklarasi variabel ex untuk jumlah kata yang sama, found jika semuanya sama
    int ex = 0, found = 0;
    // deklarasi array diisi dengan kata" yang eop
    char exit[5][10] = {"jangan",
                        "lupa",
                        "bahagia",
                        "hari",
                        "ini"};
    STARTKATA(input); // memulai mesin kata
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(GETKATA(), exit[i]) == 0) // jika kata pada inputan sama dengan yang ada di array
        {
            ex++; // ex bertambah
        }
        INCKATA(input); // menaikkan kata selanjutnya
    }
    if (ex == 5) // jika katanya sama semua
    {
        found = 1; // found diisi 1
    }
    return found; // mengembalikan nilai found
}

// untuk mengeluarkan index ke berapa data yang sudah dicari ada di file
int INDEXSEARCH()
{
    return l; // mengeluarkan l
}

// untuk menentukan tampilan yang dikeluarkan sesuai dengan query yang digunakan
void QUERYINUSE(int query, char input[])
{
    // jika query yang ditulis berjumlah lebih dari atau sama dengan 2
    if (m >= 2)
    {
        // menampilkan query yang akan dijalankan
        printf("\nTHE QUERY THAT BEING RUN:\n");
        // menggunakan switch berdasarkan variabel query
        switch (query)
        {
        case 1:                         // jika yang dijalankan adalah query ENTRI
            if (CHECKTABLE(input) == 0) // jika tabel yang dipilih adalah riders
            {
                printf("ENTRI Riders %s %s %s;\n\n", GETID(), data[0], data[1]);
            }
            else // jika tabel yang dipilih adalah motors
            {
                printf("ENTRI Motors %s %s;\n\n", GETID(), data[0]);
            }

            break;
        case 2:                         // jika yang dijalankan adalah query UBAH
            if (CHECKTABLE(input) == 0) // jika tabel yang dipilih adalah riders
            {
                printf("UBAH Riders %s %s %s;\n\n", GETID(), data[0], data[1]);
            }
            else // jika tabel yang dipilih adalah motors
            {
                printf("UBAH Motors %s %s;\n\n", GETID(), data[0]);
            }
            break;
        case 3:                         // jika yang dijalankan adalah query HAPUS
            if (CHECKTABLE(input) == 0) // jika tabel yang dipilih adalah riders
            {
                printf("HAPUS Riders %s %s %s;\n\n", GETID(), data[0], data[1]);
            }
            else // jika tabel yang dipilih adalah motors
            {
                printf("HAPUS Motors %s %s;\n\n", GETID(), data[0]);
            }
            break;
        case 4:                         // jika yang dijalankan adalah query TAMPIL
            if (CHECKTABLE(input) == 0) // jika tabel yang dipilih adalah riders
            {
                printf("TAMPIL Riders %s %s %s;\n\n", GETID(), data[0], data[1]);
            }
            else // jika tabel yang dipilih adalah motors
            {
                printf("TAMPIL Motors %s %s;\n\n", GETID(), data[0]);
            }
            break;

        default:
            break;
        }
    }
}

// untuk menghitung query yang ditulis di input
void COUNTQUERY(char pita[])
{
    STARTKATA(pita);  // memulai mesin kata
    int done = 0;     // done diisi 0 sebagai indikator
    while (done == 0) // syarat looping
    {
        if (strcmp(GETKATA(), "ENTRI") == 0) // jika input ada query ENTRI
        {
            strcpy(cquery[m], GETKATA()); // menyalin query tersebut ke cquery
            m++;                          // m bertambah
        }
        else if (strcmp(GETKATA(), "UBAH") == 0) // jika input ada query UBAH
        {
            strcpy(cquery[m], GETKATA()); // menyalin query tersebut ke cquery
            m++;                          // m bertambah
        }
        else if (strcmp(GETKATA(), "HAPUS") == 0) // jika input ada query HAPUS
        {
            strcpy(cquery[m], GETKATA()); // menyalin query tersebut ke cquery
            m++;                          // m bertambah
        }
        else if (strcmp(GETKATA(), "TAMPIL") == 0) // jika input ada query TAMPIL
        {
            strcpy(cquery[m], GETKATA()); // menyalin query tersebut ke cquery
            m++;                          // m bertambah
        }
        else
        {
            done = 1; // done diisi oleh 1
        }
        INCKATA(pita); // menaikkan kata selanjutnya
    }
}

// untuk mengecek apakah data ada di file atau tidak dalam file riders
int CHECKDATA(riders Rdata)
{
    // deklarasi variabel, s untuk mencari jumlah file yang ada di file, i dan j untuk iterator mencari record, dan ketemu untuk boolean apakah file ditemukan atau tidak
    int s = 0, i, j, ketemu = 0;
    // deklarasi variabel temp
    riders temp[100];
    FILE *frider;                                                          // deklarasi untuk variabel yang bertipe data FILE
    frider = fopen("Riders.dat", "r");                                     // file open untuk Rdata.dat mode read
    fscanf(frider, "%s %s %s", &Rdata.number, &Rdata.name, &Rdata.cmotor); // membaca isi file yang ada di file

    // looping untuk memasukkan data pada file Rdata.dat ke array temp
    do
    {
        // menyalin isi dari file Rdata ke temp
        strcpy(temp[s].name, Rdata.name);
        strcpy(temp[s].number, Rdata.number);
        strcpy(temp[s].cmotor, Rdata.cmotor);
        s++;                                                                   // s bertambah
        fscanf(frider, "%s %s %s", &Rdata.number, &Rdata.name, &Rdata.cmotor); // membaca isi file yang ada di file

    } while (strcmp(Rdata.number, "####") != 0); // syarat looping
    fclose(frider);                              // close file
                                                 // i diisi oleh 0, j diisi oleh s
    i = 0, j = s;

    // looping untuk mencari data
    while ((ketemu == 0) && (i < j)) // syarat looping
    {

        // jika kode ditemukan
        if (strcmp(temp[i].number, GETID()) == 0)
        {
            l = i;      // l diisi oleh i
            ketemu = 1; // ketemu berubah menjadi 1
        }
        // jika belum ditemukan
        else
        {
            i++; // i bertambah
        }
    }
    // mengembalikan nilai ketemu
    return ketemu;
}

// untuk mengecek table apa yang harus digunakan
int CHECKTABLE(char input[])
{

    STARTKATA(input); // memulai mesin kata
    // looping untuk INCKATA
    for (int q = 0; q < m; q++)
    {
        INCKATA(input); // menaikkan kata selanjutnya
    }
    if (strcmp(GETKATA(), "Riders") == 0) // jika tabel yang diminta riders
    {
        return 0; // return 0
    }
    else if (strcmp(GETKATA(), "Motors") == 0) // jika tabel yang diminta motors
    {
        return 1; // return 1
    }
    else
    {
        return 2; // return 2
    }
}

// untuk menjalankan query entri riders
void ENTRI(char input[], riders Rdata)
{
    // deklarasi array
    riders dRiders[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fRiders;                      // deklarasi variabel bertipe data FILE
    fRiders = fopen("Riders.dat", "r"); // file open untuk Riders.dat mode read

    fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dRiders[n].number, "####") != 0)
    {

        n++;                                                                                   // n bertambah
        fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    }
    fclose(fRiders); // close file

    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dRiders[n].number, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dRiders[n].name, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dRiders[n].cmotor, GETKATA());

    // menampilkan data yang berhasil ditambahkan ke file
    printf("\nDATA HAS BEEN SUCCESSFULLY ADDED\n\n");
    printf("Number  ");
    printf("Name   ");
    for (int i = 0; i < strlen(data[0]) - 4; i++)
    {
        printf(" ");
    }
    printf("Motor\n");
    printf("%s      %s   %s\n", GETID(), data[0], data[1]);
    fRiders = fopen("Riders.dat", "w"); // file open untuk Riders.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i <= n; i++)
    {
        fprintf(fRiders, "%s %s %s\n", &dRiders[i].number, &dRiders[i].name, &dRiders[i].cmotor); // menulis record baru ke file
    }
    fprintf(fRiders, "#### #### ####"); // menulis end of file
    fclose(fRiders);                    // close file
}

// untuk menjalankan query ubah riders
void UBAH(char input[], riders Rdata)
{
    // deklarasi array
    riders dRiders[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fRiders;                      // deklarasi variabel bertipe data FILE
    fRiders = fopen("Riders.dat", "r"); // file open untuk Riders.dat mode read

    fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dRiders[n].number, "####") != 0)
    {
        n++;                                                                                   // n bertambah
        fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    }
    fclose(fRiders); // close file

    // menyalin data ke driders dengan index dari prosedur untuk mengembalikan index yang sama
    strcpy(dRiders[INDEXSEARCH()].number, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dRiders[INDEXSEARCH()].name, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dRiders[INDEXSEARCH()].cmotor, GETKATA());

    // menampilkan data yang berhasil diubah
    printf("DATA HAS BEEN SUCCESSFULLY UPDATED\n\n");
    printf("Number  ");
    printf("Name  ");
    for (int i = 0; i < strlen(data[0]) - 4; i++)
    {
        printf(" ");
    }
    printf("Motor\n");
    printf("%s      %s  %s\n", GETID(), data[0], data[1]);
    fRiders = fopen("Riders.dat", "w"); // file open untuk Riders.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i <= n - 1; i++)
    {
        fprintf(fRiders, "%s %s %s\n", &dRiders[i].number, &dRiders[i].name, &dRiders[i].cmotor); // menulis record baru ke file
    }
    fprintf(fRiders, "#### #### ####"); // menulis end of file
    fclose(fRiders);                    // close file
}

// untuk menjalankan query hapus riders
void HAPUS(char input[], riders Rdata)
{
    // deklarasi array
    riders dRiders[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fRiders;                      // deklarasi variabel bertipe data FILE
    fRiders = fopen("Riders.dat", "r"); // file open untuk Riders.dat mode read

    fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dRiders[n].number, "####") != 0)
    {
        n++;                                                                                   // n bertambah
        fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    }
    fclose(fRiders); // close file

    // proses untuk menghapus data dengan cara memindahkan data yang dipilih ke paling ujung
    for (int i = INDEXSEARCH(); i < n; i++)
    {
        strcpy(dRiders[i].number, dRiders[i + 1].number);
        strcpy(dRiders[i].name, dRiders[i + 1].name);
        strcpy(dRiders[i].cmotor, dRiders[i + 1].cmotor);
    }

    // menampilkan data yang berhasil dihapus
    printf("DATA HAS BEEN SUCCESSFULLY DELETED\n\n");
    printf("Number  ");
    printf("Name  ");
    for (int i = 0; i < strlen(data[0]) - 4; i++)
    {
        printf(" ");
    }
    printf("Motor\n");
    printf("%s       %s %s\n", GETID(), data[0], data[1]);
    fRiders = fopen("Riders.dat", "w"); // file open untuk Riders.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i < n - 1; i++)
    {
        fprintf(fRiders, "%s %s %s\n", &dRiders[i].number, &dRiders[i].name, &dRiders[i].cmotor); // menulis record baru ke file
    }
    fprintf(fRiders, "#### #### ####"); // menulis end of file
    fclose(fRiders);                    // close file
}

// untuk menjalankan query tampil riders
void TAMPIL(char input[], riders Rdata)
{
    // deklarasi array
    riders dRiders[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fRiders;                      // deklarasi variabel bertipe data FILE
    fRiders = fopen("Riders.dat", "r"); // file open untuk Riders.dat mode read

    fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dRiders[n].number, "####") != 0)
    {
        n++;                                                                                   // n bertambah
        fscanf(fRiders, "%s %s %s", &dRiders[n].number, &dRiders[n].name, &dRiders[n].cmotor); // membaca isi file yang ada di file
    }
    fclose(fRiders); // close file

    // untuk menghitung string terpanjang
    int longest2 = strlen(dRiders[0].name);
    for (int i = 1; i < n; i++)
    {
        int temp = strlen(dRiders[i].name);
        if (longest2 < temp)
        {
            longest2 = temp;
        }
    }

    // proses menampilkan semua data
    printf("\nHERE IS THE DATA:\n");

    printf("Number  ");
    for (int i = 0; i < 2; i++)
    {
        printf(" ");
    }
    printf("Name  ");
    for (int i = 0; i < longest2 - 4; i++)
    {
        printf(" ");
    }
    printf("Motor\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s  ", dRiders[i].number);
        for (int j = 0; j < 6; j++)
        {
            printf(" ");
        }
        printf("%s  ", dRiders[i].name);
        for (int j = 0; j < longest2 - strlen(dRiders[i].name); j++)
        {
            printf(" ");
        }
        printf("%s\n", dRiders[i].cmotor);
    }
}

// untuk mengecek apakah data ada di file atau tidak dalam file motors
int CHECKDATAMOTORS(motors Rdata)
{
    // deklarasi variabel, s untuk mencari jumlah file yang ada di file, i dan j untuk iterator mencari record,dan ketemu untuk boolean apakah file ditemukan atau tidak
    int s = 0, i, j, k, ketemu = 0;
    // deklarasi variabel temp
    motors temp[100];
    FILE *fmotor;                                         // deklarasi untuk variabel yang bertipe data FILE
    fmotor = fopen("Motors.dat", "r");                    // file open untuk Motors.dat mode read
    fscanf(fmotor, "%s %s", &Rdata.cmotor, &Rdata.motor); // membaca isi file yang ada di file

    // looping untuk memasukkan data pada file Motors.dat ke array temp
    do
    {
        // menyalin isi dari file Rdata ke temo
        strcpy(temp[s].cmotor, Rdata.cmotor);
        strcpy(temp[s].motor, Rdata.motor);
        s++;                                                  // s bertambah
        fscanf(fmotor, "%s %s", &Rdata.cmotor, &Rdata.motor); // membaca isi file yang ada di file

    } while (strcmp(Rdata.cmotor, "####") != 0); // syarat looping
    fclose(fmotor);                              // close file

    i = 0, j = s; // i diisi oleh 0, j diisi oleh s

    // looping untuk mencari data yang sama
    while ((ketemu == 0) && (i < j)) // syarat looping
    {
        // jika kode ditemukan
        if (strcmp(temp[i].cmotor, GETID()) == 0)
        {
            l = i;      // l diisi oleh i
            ketemu = 1; // ketemu berubah menjadi 1
        }
        // jika belum ditemukan
        else
        {
            i++; // i bertambah
        }
    }
    // mengembalikan nilai ketemu
    return ketemu;
}

// untuk menjalankan query entri motors
void ENTRIMOTOR(char input[], motors Rdata)
{
    // deklarasi array
    motors dMotors[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fMotors;                      // deklarasi variabel bertipe data FILE
    fMotors = fopen("Motors.dat", "r"); // file open untuk Motors.dat mode read

    fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dMotors[n].cmotor, "####") != 0)
    {
        n++;                                                             // n bertambah
        fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    }
    fclose(fMotors); // close file

    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dMotors[n].cmotor, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dMotors[n].motor, GETKATA());

    // menampilkan data yang berhasil dimasukkan ke file
    printf("DATA HAS BEEN SUCCESSFULLY ADDED\n\n");
    printf("Code Motor  ");
    printf("Motor\n");
    printf("%s", GETID());
    for (int j = 0; j < 9; j++)
    {
        printf(" ");
    }
    printf("%s\n", data[0]);

    fMotors = fopen("Motors.dat", "w"); // file open untuk Motors.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i <= n; i++)
    {
        fprintf(fMotors, "%s %s\n", &dMotors[i].cmotor, &dMotors[i].motor); // menulis record baru ke file
    }
    fprintf(fMotors, "#### ####"); // menulis end of file
    fclose(fMotors);               // close file
}

// untuk menjalankan query ubah motors
void UBAHMOTOR(char input[], motors Rdata)
{
    // deklarasi array
    motors dMotors[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fMotors;                      // deklarasi variabel bertipe data FILE
    fMotors = fopen("Motors.dat", "r"); // file open untuk Motors.dat mode read

    fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dMotors[n].cmotor, "####") != 0)
    {
        n++;                                                             // n bertambah
        fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    }
    fclose(fMotors); // close file

    // menyalin data ke driders dengan index dari prosedur untuk mengembalikan index yang sama
    strcpy(dMotors[INDEXSEARCH()].cmotor, GETKATA());
    INCKATA(input); // menaikkan kata selanjutnya
    strcpy(dMotors[INDEXSEARCH()].motor, GETKATA());

    // menampilkan data yang berhasil diubah
    printf("\nDATA HAS BEEN SUCCESSFULLY UPDATED\n\n");
    printf("Code Motor  ");
    printf("Motor\n");
    printf("%s", GETID());
    for (int j = 0; j < 9; j++)
    {
        printf(" ");
    }
    printf("%s\n", data[0]);
    fMotors = fopen("Motors.dat", "w"); // file open untuk Motors.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i <= n - 1; i++)
    {
        fprintf(fMotors, "%s %s\n", &dMotors[i].cmotor, &dMotors[i].motor); // menulis record baru ke file
    }
    fprintf(fMotors, "#### ####"); // menulis end of file
    fclose(fMotors);               // close file
}

// untuk menjalankan query hapus motors
void HAPUSMOTOR(char input[], motors Rdata)
{
    // deklarasi array
    motors dMotors[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fMotors;                      // deklarasi variabel bertipe data FILE
    fMotors = fopen("Motors.dat", "r"); // file open untuk Motors.dat mode read

    fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dMotors[n].cmotor, "####") != 0)
    {
        n++;                                                             // n bertambah
        fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    }
    fclose(fMotors); // close file

    // proses menghapus data yang diminta
    for (int i = INDEXSEARCH(); i < n; i++)
    {
        strcpy(dMotors[i].cmotor, dMotors[i + 1].cmotor);
        strcpy(dMotors[i].motor, dMotors[i + 1].motor);
    }

    // menampilkan data yang berhasil dihapus
    printf("\nDATA HAS BEEN SUCCESSFULLY DELETED\n\n");
    printf("Code Motor  ");
    printf("Motor\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s", GETID());
        for (int j = 0; j < 9; j++)
        {
            printf(" ");
        }
        printf("%s\n", data[0]);
    }
    fMotors = fopen("Motors.dat", "w"); // file open untuk Motors.dat mode write

    // looping untuk menulis record baru
    for (i = 0; i < n - 1; i++)
    {
        fprintf(fMotors, "%s %s\n", &dMotors[i].cmotor, &dMotors[i].motor); // menulis record baru ke file
    }
    fprintf(fMotors, "#### ####"); // menulis end of file
    fclose(fMotors);               // close file
}

// untuk menjalankan query tampil motors
void TAMPILMOTOR(char input[], motors Rdata)
{

    // deklarasi array
    motors dMotors[100];
    // deklarasi i dan n
    int i, n = 0;
    FILE *fMotors;                      // deklarasi variabel bertipe data FILE
    fMotors = fopen("Motors.dat", "r"); // file open untuk Motors.dat mode read

    fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    // looping untuk membaca semua record
    while (strcmp(dMotors[n].cmotor, "####") != 0)
    {
        n++;                                                             // n bertambah
        fscanf(fMotors, "%s %s", &dMotors[n].cmotor, &dMotors[n].motor); // membaca isi file yang ada di file
    }
    fclose(fMotors); // close file

    // mencari string terpanjang
    int longest2 = strlen(dMotors[0].motor);
    for (int i = 1; i < n; i++)
    {
        int temp = strlen(dMotors[i].motor);
        if (longest2 < temp)
        {
            longest2 = temp;
        }
    }

    // menampilkan semua data yang ada di file
    printf("\nHERE IS THE DATA:\n");
    printf("Code Motor   ");
    printf("Motor\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s", dMotors[i].cmotor);
        for (int j = 0; j < 10; j++)
        {
            printf(" ");
        }
        printf("%s\n", dMotors[i].motor);
    }
}
