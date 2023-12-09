// Deskripsi Soal
/*
	Hari ini orang tua Clayton pergi menemui Wali Kelas Clayton karena nilai Clayton menurun. Setelah diselidiki hal itu disebabkan karena Clayton selalu duduk di barisan paling belakang. Sang wali kelas pun mengusulkan sebuah ide
	untuk menukar tempat duduk muridnya setiap seminggu sekali. Pertukaran tempat duduk dilakukan dengan
	syarat nilai rata-rata siswa yang akan ditukar di barisan belakang lebih kecil dibandingkan nilai rata-rata
	siswa yang berada di barisan depan. Pertukaran tempat duduk dilakukan hingga semua siswa memiliki nilai yang
	baik, itu ditandai dengan kata Selesai.

	Format Masukan :
	n baris matriks tipe bungkusan, n > 0
	m kolom matriks tipe bungkusan, m > 0
	n x m data matriks tipe bungkusan nama, nilai Matematika, IPA, English
	nama siswa yang ditukar posisi duduknya

	Format Keluaran :
	Posisi tempat duduk awal
	Posisi tempat duduk akhir
*/

// Janji
/*
    Saya Mia Karisma Haq Asisten Pemrograman 13 dengan penuh kesadaran dan tanggung jawab untuk keberkahanNya membuat pembahasan soal TP2 dalam mata kuliah Algoritma dan Pemrograman 2 seperti yang telah dispesifikasikan. Aamiin
*/

// Kode Program
// Deklarasi Library yang digunakan
#include <stdio.h>
#include <string.h>

// Deklarasi tipe data terstruktur
typedef struct
{
	// Variabel yang terdapat dalam bungkusan
    char nama[100]; // String nama untuk menampung nama mahasiswa 
    int nilai[3]; // Array of integer nilai untuk menampung nilai Matematika, IPA, English
    int avg; // Variabel untuk menampung nilai rata-rata dari setiap mahasiswa
}bungkusanData; // Nama tipe data terstruktur

//Prosedur untuk menampilkan posisi bangku
void output(int kolom, int baris, bungkusanData data[][kolom]) { 
	int i, j, l; //Variabel untuk kontrol perulangan untuk alokasi matriks tipe terstruktur
	int max[kolom]; //Array of integer untuk menentukan panjang string terpanjang setiap kolom
	
	//Perulangan untuk menentukan panjang string terpanjang setiap kolom
	for(i = 0; i < kolom; i++) {
		max[i] = 0; //Inisialisasi
		for(j = 0; j < baris; j++) {
			if(strlen(data[j][i].nama) > max[i]) { //Jika panjang string nama mahasiswa lebih besar dari nilai max indeks ke-i
				max[i] = strlen(data[j][i].nama); //Maka nilai max indeks ke-i diisi oleh panjang string nama mahasiswa 
			}
		}
	}
	
	//Perulangan untuk menampilkan posisi bangku
	for(i = 0; i < baris; i++) {
		for(j = 0; j < kolom; j++) {
			printf("%s", data[i][j].nama); //Menampilkan nama mahasiswa
			if(j != kolom - 1) { //Jika indeks bukan indeks terakhir kolom matriks tipe terstruktur
				//Maka tampilkan spasi sebanyak panjang string terpanjang dikurangi panjang string nama mahasiswa tersebut
				for(l = 0; l < (max[j] - strlen(data[i][j].nama)); l++) { 
					printf(" ");
				}
				printf(" "); //Menampilkan spasi tengah
			}
		}
		printf("\n"); //Menampilkan baris baru
	}
}

//Prosedur untuk menukar posisi tempat duduk
void cari(char nama[], char tukar[], int *baris, int *kolom, int i, int j, int *tanda) {
	if(strcmp(nama, tukar) == 0) { //Jika nama mahasiswa yang akan ditukar sama seperti nama mahasiswa masukan awal user
		//Maka indeks baris diisi indeks ke-i, indeks kolom diisi indeks ke-j dan nilai tanda bertambah
		*baris = i; 
		*kolom = j;
		*tanda = *tanda + 1;
	}
}

void tukar(int n, int m, bungkusanData matriks[][m], char kiri[], char kanan[])
{
	int index1[2]; // Array of integer untuk menampung indeks nama mahasiswa sebelah kiri yang posisi tempat duduknya akan ditukar
	int index2[2]; // Array of integer untuk menampung indeks nama mahasiswa sebelah kanan yang posisi tempat duduknya akan ditukar
	int i, j, l; // Variabel untuk kontrol perulangan untuk alokasi matriks tipe terstruktur
	int tanda = 0; // Variabel untuk menandakan bahwa nilai rata-rata mahasiswa sebelah kiri dan kanan telah terisi
	int temp = 0; // Variabel untuk menampung sementara nilai rata-rata mahasiswa yang akan ditukar
    char ubah[100]; // String untuk menyimpan nama mahasiswa yang akan diubah posisi tempat duduknya

	//Perulangan untuk menukar posisi tempat duduk mahasiswa
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			cari(matriks[i][j].nama, kiri, &index1[0], &index1[1], i, j, &tanda); // Memanggil prosedur untuk mencari indeks posisi tempat duduk mahasiswa sebelah kiri yang akan ditukar
			cari(matriks[i][j].nama, kanan, &index2[0], &index2[1], i, j, &tanda); // Memanggil prosedur untuk mencari indeks posisi tempat duduk mahasiswa sebelah kanan yang akan ditukar
			if(tanda == 2) { // Jika nilai rata-rata mahasiswa sebelah kiri dan kanan telah terisi
				if(index1[0] < index2[0] && matriks[index1[0]][index1[1]].avg > matriks[index2[0]][index2[1]].avg || index1[0] > index2[0] && matriks[index1[0]][index1[1]].avg < matriks[index2[0]][index2[1]].avg) { // Jika nilai rata-rata mahasiswa di barisan belakang kurang dari rata-rata mahasiswa di barisan depan
					temp = matriks[index1[0]][index1[1]].avg; // Maka sementara pindahkan nilai rata-rata mahasiswa sebelah kiri ke temp
					matriks[index1[0]][index1[1]].avg = matriks[index2[0]][index2[1]].avg; // Dan nilai rata-rata mahasiswa sebelah kiri diisi nilai rata-rata mahasiswa sebelah kanan
					matriks[index2[0]][index2[1]].avg = temp; // Lalu isi nilai rata-rata mahasiswa sebelah kanan dengan temp yang berisi nilai rata-rata mahasiswa sebelah kiri
					strcpy(ubah, matriks[index1[0]][index1[1]].nama); // Menyalin nama mahasiswa sebelah kiri yang posisi tempat duduknya akan ditukar ke dalam string ubah
					strcpy(matriks[index1[0]][index1[1]].nama, matriks[index2[0]][index2[1]].nama); // Menyalin nama mahasiswa sebelah kanan yang posisi tempat duduknya akan ditukar ke sebelah kiri
					strcpy(matriks[index2[0]][index2[1]].nama, ubah); // Menyalin nama mahasiswa sebelah kiri yang posisi tempat duduknya akan ditukar ke sebelah kanan 
				}
				tanda = 0; // Setelah proses penukaran posisi tempat duduk, nilai tanda kembali menjadi 0
			}
		}
	}
}

// Program Utama
int main()
{
    int n, m; scanf("%d%d", &n, &m); // Meminta masukan ordo matriks terstruktur kepada user
    int i, j, k, l; //Variabel untuk kontrol perulangan untuk alokasi matriks tipe terstruktur
    bungkusanData matriksAkhir[n][m]; // Deklarasi matriks tipe data terstruktur
	bungkusanData matriksAwal[n][m]; // Deklarasi matriks tipe data terstruktur untuk menyimpan 
    char kiri[100]; // String untuk menyimpan nama mahasiswa di ruas kiri yang akan ditukar (Disini menggunakan kata kiri karena belum diketahui apakah nama yang pertama kali disebut ada di baris depan atau belakang)
    char kanan[100]; // String untuk menyimpan nama mahasiswa di ruas kanan yang akan ditukar

	/* Perulangan untuk meminta masukan data matriks dari user */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
           scanf("%s%d%d%d", &matriksAwal[i][j].nama, &matriksAwal[i][j].nilai[0], &matriksAwal[i][j].nilai[1], &matriksAwal[i][j].nilai[2]);
			// Menghitung rata-rata
           matriksAwal[i][j].avg = (matriksAwal[i][j].nilai[0] + matriksAwal[i][j].nilai[1] + matriksAwal[i][j].nilai[2])/3;
			// Menyalin isi matriks masukan awal user ke dalam matriks akhir
		   matriksAkhir[i][j] = matriksAwal[i][j];
        }
    }
	
	/* Perulangan untuk meminta masukan nama-nama siswa yang akan ditukar */
    do
    {
        scanf("%s", kiri);
        if (strcmp(kiri, "Selesai") != 0) 
		{
			scanf("%s", kanan);
			// Proses menukar tempat duduk siswa
			tukar(n, m, matriksAkhir, kiri, kanan);
		}
    } while (strcmp(kiri, "Selesai") != 0);
    
   	// Menampilkan Posisi Bangku awal mahasiswa
	printf("Posisi awal :\n");
	output(m, n, matriksAwal); // Memanggil prosedur untuk menampilkan posisi bangku
	printf("\n"); // Menampilkan baris baru
	
	// Menampilkan posisi bangku akhir setelah memeriksa nilai rata-rata
	printf("Posisi akhir :\n");
	output(m, n, matriksAkhir); // Memanggil prosedur untuk menampilkan posisi bangku
    
    return 0; // Menyatakan keluaran dari fungsi main() adalah true
}