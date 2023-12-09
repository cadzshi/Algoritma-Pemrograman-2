#include "header.h"

void init() // prosedur yang dipanggil saat program baru dijalankan
{
    // scan setiap file dan isi masing-masing array
    fscanf_film(f_list_film, "data/ListFilm.dat", a_list_film);
    fscanf_data(f_sutradara, "data/Sutradara.dat", a_sutradara, &n_sutradara);
    fscanf_data(f_genre, "data/Genre.dat", a_genre, &n_genre);
    fscanf_data(f_bioskop, "data/Bioskop.dat", a_bioskop, &n_bioskop);
    // ubah setiap id di list film menjadi nama di list film final
    proses_list_film_final();
    // tampilkan menu awal
    menu_utama();
}

void fscanf_film(FILE* f, char s[], film a[])   // prosedur untuk mengisi array list film atau list film final
{
    f = fopen(s, "r");  // buka file
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s %s %s", a[i].judul, a[i].sutradara, a[i].genre, a[i].bioskop); // scan setiap baris dalam file
        if (strcmp(a[i].judul, "####") == 0) dummy = 1; // hingga bertemu data dummy
        else i++;
    }
    while (dummy == 0);
    n_list_film = i;    // ukuran/jumlah elemen array sama saja dengan nilai variabel i
    fclose(f);  // tutup file
}

void fscanf_data(FILE* f, char s[], data a[], int* n)   // prosedur untuk mengisi array sutradara, genre, atau bioskop
{
    // prosesnya mirip sama prosedur diatas
    f = fopen(s, "r");
    int i = 0, dummy = 0;
    do
    {
        fscanf(f, "%s %s", a[i].id, a[i].nama); // tapi yang dibaca hanya id dan nama
        if (strcmp(a[i].id, "####") == 0) dummy = 1;
        else i++;
    }
    while (dummy == 0);
    *n = i; // dan ukuran array diubah melalui pass by reference
    fclose(f);
}

void fprintf_film(FILE* f, char s[], film a[])  // prosedur untuk mengubah isi file list film atau list film final
{
    f = fopen(s, "w");  // buka file
    for (int i = 0; i < n_list_film; i++)
    {
        fprintf(f, "%s %s %s %s\n", a[i].judul, a[i].sutradara, a[i].genre, a[i].bioskop);  // tuliskan masing-masing elemen array ke dalam file
    }
    fprintf(f, "#### #### #### ####");  // lalu tutup file dengan data dummy
    fclose(f);  // tutup file
}

void fprintf_data(FILE* f, char s[], data a[], int n)   // prosedur untuk mengubah isi file sutradara, genre, atau bioskop
{
    // sekali lagi, ini mirip prosedur diatas
    f = fopen(s, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %s\n", a[i].id, a[i].nama);  // tapi cuma id sama nama doang
    }
    fprintf(f, "#### ####");
    fclose(f);
}

void printf_film(film a[])  // prosedur untuk menampilkan isi array list film atau list film final ke console
{
    // deklarasi variabel2 untuk panjang string terpanjang di setiap kolom
    // nilai inisialisasi awal mengikuti nama kolom, contoh "Judul" = 5 karakter, "Sutradara" = 9 karakter
    int longest_j = 5, longest_s = 9, longest_g = 5, longest_b = 7;
    for (int i = 0; i < n_list_film; i++)   // loop untuk mencari string terpanjang di masing2 kolom  
    {
        if (strlen(a[i].judul) > longest_j) longest_j = strlen(a[i].judul);
        if (strlen(a[i].sutradara) > longest_s) longest_s = strlen(a[i].sutradara);
        if (strlen(a[i].genre) > longest_g) longest_g = strlen(a[i].genre);
        if (strlen(a[i].bioskop) > longest_b) longest_b = strlen(a[i].bioskop);
    }
    // mulai print tabel sesuai pola
    garis_film(longest_j, longest_s, longest_g, longest_b); // ini nanti liat aja isi prosedurnya kaya gimana
    // print header tabel
    printf("| Judul");
    for (int i = 0; i < longest_j - 5; i++) printf(" ");
    printf(" | Sutradara");
    for (int i = 0; i < longest_s - 9; i++) printf(" ");
    printf(" | Genre");
    for (int i = 0; i < longest_g - 5; i++) printf(" ");
    printf(" | Bioskop");
    for (int i = 0; i < longest_b - 7; i++) printf(" ");
    printf(" |\n");
    garis_film(longest_j, longest_s, longest_g, longest_b);
    // print isi tabel
    for (int i = 0; i < n_list_film; i++)
    {
        printf("| %s", a[i].judul); // print elemen ke i dari array
        for (int j = 0; j < longest_j - strlen(a[i].judul); j++) printf(" ");   // terus print spasi biar rapih
        printf(" | %s", a[i].sutradara);    // print pembatas '|' dan ulangi proses sebelumnya untuk kolom lain
        for (int j = 0; j < longest_s - strlen(a[i].sutradara); j++) printf(" ");
        printf(" | %s", a[i].genre);
        for (int j = 0; j < longest_g - strlen(a[i].genre); j++) printf(" ");
        printf(" | %s", a[i].bioskop);
        for (int j = 0; j < longest_b - strlen(a[i].bioskop); j++) printf(" ");
        printf(" |\n");
    }
    garis_film(longest_j, longest_s, longest_g, longest_b);
    printf("\nMasukkan karakter apapun untuk kembali ke menu utama : ");
    scanf("%s");    // scanf kosong agar program tidak langsung kembali ke menu utama atau keluar
    menu_utama();
}

void printf_data(data a[], int n)   // prosedur untuk menampilkan isi array sutradara, genre, atau bioskop ke console
{
    // sama aja kaya prosedur sebelumnya tapi hanya ada satu variable longest untuk kolom nama
    // kolom id nilainya dianggap selalu konstan 4 karakter, contoh "S069"
    int longest = 4;
    for (int i = 0; i < n; i++)
    {
        if (strlen(a[i].nama) > longest) longest = strlen(a[i].nama);
    }
    garis_data(longest);
    printf("| ID   | Nama");
    for (int i = 0; i < longest - 4; i++) printf(" ");
    printf(" |\n");
    garis_data(longest);
    for (int i = 0; i < n; i++)
    {
        printf("| %s | %s", a[i].id, a[i].nama);
        for (int j = 0; j < longest - strlen(a[i].nama); j++) printf(" ");
        printf(" |\n");
    }
    garis_data(longest);
    printf("\nMasukkan karakter apapun untuk kembali ke menu utama : ");
    scanf("%s");
    menu_utama();
}

void garis_film(int j, int s, int g, int b) // biar ga usah ngetik berulang kali, jadi dijadiin prosedur deh
{
    // parameter j, s, g, b itu panjang string terpanjang di masing2 kolom
    printf("+-");
    for (int i = 0; i < j; i++) printf("-");
    printf("-+-");
    for (int i = 0; i < s; i++) printf("-");
    printf("-+-");
    for (int i = 0; i < g; i++) printf("-");
    printf("-+-");
    for (int i = 0; i < b; i++) printf("-");
    printf("-+\n");
}

void garis_data(int l)  // sama... aja... kaya... diatas...
{
    // tapi... menyesuaikan...
    printf("+------+-");
    for (int i = 0; i < l; i++) printf("-");
    printf("-+\n");
}

void proses_list_film_final()   // prosedur yang gunanya sesuai namanya... hadeh cape
{
    f_list_film_final = fopen("data/ListFilmFinal.dat", "w");    // buka puasa
    for (int i = 0; i < n_list_film; i++)
    {
        data s = binary_search(a_sutradara, 0, n_sutradara - 1, a_list_film[i].sutradara);  // cari nama sutradara berdarkan id di list film
        data g = binary_search(a_genre, 0, n_genre - 1, a_list_film[i].genre);  // cari nama genre berdasarkan id di list film
        data b = binary_search(a_bioskop, 0, n_bioskop - 1, a_list_film[i].bioskop);    // cari nama bioskop berdasarkan id di list film
        fprintf(f_list_film_final, "%s %s %s %s\n", a_list_film[i].judul, s.nama, g.nama, b.nama);  // masukkan judul beserta nama2 yang sudah dicari
    }
    fprintf(f_list_film_final, "#### #### #### ####");  // isi file dengan data dummy
    fclose(f_list_film_final);  // tutup puasa
    fscanf_film(f_list_film_final, "data/ListFilmFinal.dat", a_list_film_final); // nah terus isi array list film final berdasarkan file list film final
}

data binary_search(data a[], int l, int r, char s[])    // binary search... ya binary search
{
    if (l <= r) // selama index kiri tidak lebih kecil dari index kanan
    {
        int m = (l + r) / 2;    // cari index tengah
        // jika nilai di index tengah lebih kecil dari nilai yang dicari, lanjut cari ke sebelah kanan array
        if (strcmp(a[m].id, s) < 0) return binary_search(a, m + 1, r, s);
        // jika nilai di index tengah lebih besar dari nilai yang dicari, lanjut cari ke sebelah kiri array
        if (strcmp(a[m].id, s) > 0) return binary_search(a, l, m - 1, s);
        // jika kedua kondisi diatas tidak terpenuhi artinya nilai di index tengah sama dengan nilai index yang dicari
        return a[m];    // jadi kasihin aja data dari array di index tengah
        // fungsi cuma bisa return 1 kali dan semua line dibawah return ga bakal dijalanin
        // jadi kondisi2 diatas gausah pake else if / else
        printf("Ga akan diprint\n"); // nih buktinya tulisan ini ga akan diprint sama sekali
    }
    // empat line dibawah ini cuma bakal jalan kalo ternyata nilai yang dicari gaada di dalam array
    // kenapa bisa gitu? ya... pokoknya bisa
    data temp;
    strcpy(temp.id, s);
    strcpy(temp.nama, "????");  // kalo gaada, kasihin data yang isi namanya "????"
    return temp;
}

void cari_data(char c)  // prosedur buat mencari takjil, aduh maaf ini nulis komennya menjelang maghrib
{
    system("cls");  // bersihin console
    char kategori[4][24] = {"sutradara", "genre", "bioskop", "sutradara/genre/bioskop"};    // string buat masing2 pilihan
    // Kasih pesan Cari data (...) sesuai pilihan
    printf("Cari data %s\n\n", kategori[c - 49]);
    // terus suruh user masukin id
    printf("Masukkan ID %s yang ingin dicari : ", kategori[c - 49]);
    char cari[5];
    scanf("%s", cari);  // terus ya di scan
    data hasil;
    // terus isi variabel hasil pake binary search sesuai pilihan
    if (c == '1') hasil = binary_search(a_sutradara, 0, n_sutradara - 1, cari);
    else if (c == '2') hasil = binary_search(a_genre, 0, n_genre - 1, cari);
    else if (c == '3') hasil = binary_search(a_bioskop, 0, n_bioskop - 1, cari);
    else
    {
        // ini kalo user milih pilihan keseluruhan
        hasil = binary_search(a_sutradara, 0, n_sutradara - 1, cari);   // caranya cari dulu id di sutradara
        if (strcmp(hasil.nama, "????") == 0)    // kalo teryata gaada
        {
            hasil = binary_search(a_genre, 0, n_genre - 1, cari);   // lanjut cari id di genre
            if (strcmp(hasil.nama, "????") == 0)    // kalo masih gaada
            {
                hasil = binary_search(a_bioskop, 0, n_bioskop - 1, cari);   // lanjut cari di bioskop
            }
        }
        // kalo masih gaada gimana? ya berarti emang gaada id nya
    }
    if (strcmp(hasil.nama, "????") == 0)    // kalo datanya gaada
    {
        printf("\nData %s dengan ID %s tidak ditemukan\n", kategori[c - 49], cari); // bilang gini
    }
    else    // kalo ada
    {
        printf("\nData %s dengan ID %s ditemukan dengan nama \"%s\"\n", kategori[c - 49], cari, hasil.nama);    // bilang gini
    }
    printf("\nMasukkan karakter apapun untuk kembali ke menu utama : ");
    scanf("%s");    // biar... biar apa ini tadi lupa
    menu_utama();
}

void insert_film()  // ada prosedur insert dong biar dapet bonus ehe
{
    // ini gausah pake parameter sama sekali soalnya user cuma bisa insert film ke list film doang dan semua variabel yang dibutuhin global :D
    system("cls");
    film baru;
    printf("Insert record List Film\n\n");
    // suruh user masukkin atributnya satu2
    printf("Masukkan Judul film baru   : ");
    scanf("%s", baru.judul);
    printf("Masukkan ID Sutradara film : ");
    scanf("%s", baru.sutradara);
    printf("Masukkan ID Genre film     : ");
    scanf("%s", baru.genre);
    printf("Masukkan ID Bioskop film   : ");
    scanf("%s", baru.bioskop);
    printf("\nRecord List Film baru berhasil ditambahkan\n\n"); // ini sebenernya gaada kondisi gagalnya sih wkwkwk
    a_list_film[n_list_film] = baru;    // nah film baru otomatis masuk ke elemen terakhir array karena emang ga perlu ngurut filmnya
    n_list_film++;  // ukuran array film juga nambah atu
    fprintf_film(f_list_film, "data/ListFilm.dat", a_list_film); // tulis ulang file biar film yang baru diinsert juga masuk
    proses_list_film_final();   // karena list film final bergantung sama list film jadi abis insert harus diproses ulang
    printf_film(a_list_film);   // tunjukin semua record biar keliatan aja berhasil insert
}

void insert_data(data a[], int* n, char c)  // nah buat insert data ada tambahan dikit
{
    system("cls");
    char kategori[3][10] = {"sutradara", "genre", "bioskop"};   // string buat masing2 pilihan
    data baru;
    printf("Insert record %s\n\n", kategori[c - 50]);
    printf("Masukkan ID %s baru   : ", kategori[c - 50]);
    scanf("%s", baru.id);
    printf("Masukkan nama %s baru : ", kategori[c - 50]);
    scanf("%s", baru.nama);
    printf("\nRecord %s baru berhasil ditambahkan\n\n", kategori[c - 50]);
    // karena data nya harus terurut, jadi insertnya sedikit ribet
    int i = *n - 1; // iterator mulai dari belakang array
    while (strcmp(baru.id, a[i].id) < 0 && i >= 0)  // ini loop nya bisa jalan terus sampe i = 0 atau ga jalan sama sekali, tergantung nilai data barunya
    {
        a[i + 1] = a[i]; // geser elemen array ke kanan
        i--;    // terus iterator pindah ke kiri
    }
    a[i + 1] = baru;    // terus masukin data baru di index pas loop nya berhenti
    *n += 1;    // pass by reference ukuran arraynya ditambah 1
    // terus ubah isi file sesuai pilihan
    if (c == '2') fprintf_data(f_sutradara, "data/Sutradara.dat", a, *n);
    else if (c == '3') fprintf_data(f_genre, "data/Genre.dat", a, *n);
    else fprintf_data(f_bioskop, "data/Bioskop.dat", a, *n);
    proses_list_film_final(); // list film final juga harus diproses ulang, karena bisa jadi sebelumnya ada data yang kurang lengkap
    printf_data(a, *n); // tunjukin semua record biar keliatan berhasil insert
}

// buat prosedur menu intinya tunjukin semua pilihan ke user
// terus usernya masukin satu angka
// terus pindah ke prosedur lain sesuai angka masukan
void menu_utama()
{
    system("cls");
    printf("Tugas Praktikum 7 & 8 Fauzan\n\n");
    printf("+----------------------------+\n");
    printf("|         Menu Utama         |\n");
    printf("+----+-----------------------+\n");
    printf("| No | Deskripsi             |\n");
    printf("+----+-----------------------+\n");
    printf("| 1  | Tampilkan records     |\n");
    printf("| 2  | Cari record           |\n");
    printf("| 3  | Insert record         |\n");
    printf("| 0  | Tutup program         |\n");
    printf("+----+-----------------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    if (pilihan == '0') return;
    else if (pilihan == '1') menu_print();
    else if (pilihan == '2') menu_cari();
    else if (pilihan == '3') menu_insert();
    else menu_utama();
}

void menu_print()
{
    system("cls");
    printf("+----------------------+\n");
    printf("|  Tampilkan  records  |\n");
    printf("+----+-----------------+\n");
    printf("| No | Deskripsi       |\n");
    printf("+----+-----------------+\n");
    printf("| 1  | List film       |\n");
    printf("| 2  | Sutradara       |\n");
    printf("| 3  | Genre           |\n");
    printf("| 4  | Bioskop         |\n");
    printf("| 5  | List film final |\n");
    printf("| 0  | Menu sebelumnya |\n");
    printf("+----+-----------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    system("cls");
    // tapi buat menu_print beda, ada keterangan tambahan dikit
    char kategori[5][16] = {"List Film", "Sutradara", "Genre", "Bioskop", "List Film Final"};
    printf("Records %s\n\n", kategori[pilihan - 49]);
    if (pilihan == '0') menu_utama();
    else if (pilihan == '1') printf_film(a_list_film);
    else if (pilihan == '2') printf_data(a_sutradara, n_sutradara);
    else if (pilihan == '3') printf_data(a_genre, n_genre);
    else if (pilihan == '4') printf_data(a_bioskop, n_bioskop);
    else if (pilihan == '5') printf_film(a_list_film_final);
    else menu_print();
}

void menu_cari()
{
    system("cls");
    printf("+----------------------+\n");
    printf("|     Cari  record     |\n");
    printf("+----+-----------------+\n");
    printf("| No | Deskripsi       |\n");
    printf("+----+-----------------+\n");
    printf("| 1  | Sutradara       |\n");
    printf("| 2  | Genre           |\n");
    printf("| 3  | Bioskop         |\n");
    printf("| 4  | Keseluruhan     |\n");
    printf("| 0  | Menu sebelumnya |\n");
    printf("+----+-----------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    if (pilihan == '0') menu_utama();
    else if (pilihan >= '1' && pilihan <= '4') cari_data(pilihan);
    else menu_print();
}

void menu_insert()
{
    system("cls");
    printf("+----------------------+\n");
    printf("|    Insert  record    |\n");
    printf("+----+-----------------+\n");
    printf("| No | Deskripsi       |\n");
    printf("+----+-----------------+\n");
    printf("| 1  | List film       |\n");
    printf("| 2  | Sutradara       |\n");
    printf("| 3  | Genre           |\n");
    printf("| 4  | Bioskop         |\n");
    printf("| 0  | Menu sebelumnya |\n");
    printf("+----+-----------------+\n");
    printf("\nMasukkan angka sesuai pilihan yang diinginkan : ");
    char pilihan;
    scanf(" %c", &pilihan);
    if (pilihan == '0') menu_utama();
    else if (pilihan == '1') insert_film();
    else if (pilihan == '2') insert_data(a_sutradara, &n_sutradara, pilihan);
    else if (pilihan == '3') insert_data(a_genre, &n_genre, pilihan);
    else if (pilihan == '4') insert_data(a_bioskop, &n_bioskop, pilihan);
    else menu_insert();
}