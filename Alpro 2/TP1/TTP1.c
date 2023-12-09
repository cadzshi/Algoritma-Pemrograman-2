// Deskripsi Soal
/*
Buatlah sebuah teka-teki, dimana teka-teki tersebut terdiri dari sebuah matriks dinamis yang dapat melakukan sejumlah operasi sebagai berikut :
Jumlahkan total baris terakhir dengan total kolom terakhir pada matriks, Apabila hasil penjumlahan bernilai genap, 
maka lakukan rotasi ke kanan, dan jika bernilai ganjil maka lakukan rotasi ke kiri pada matriks tersebut. 
Dimana rotasi dilakukan sebanyak hasil penjumlahan modulo 4 (Jika 0 maka tidak terjadi perputaran).
Setelah dilakukan rotasi, periksa apakah matriks hasil rotasi sama seperti matriks awal masukan user atau berbeda.
Jika sama, maka lakukan refleksi lalu tampilkan "Teka-teki berhasil dipecahkan!" dan jika berbeda maka lakukan transpose lalu tampilkan "Teka-teki terlalu sulit!".

Masukan
n baris matriks, n > 0
m kolom matriks, m > 0
n x m data matriks

Keluaran
matriks awal
matriks akhir hasil refleksi atau transpose

Masukan 1						    Masukan 2						Masukan 3 						Masukan 4
2 3							        2 2							    3 2						        3 3
1 1 1							    1 3							    1 2						        1 2 3
2 3 4							    2 4							    1 1						        3 3 3
												                    2 1							    0 4 3

Keluaran 1						    Keluaran 2						Keluaran 3						Keluaran 4
Matriks awal :					    Matriks awal :					Matriks awal :					Matriks awal :
1 1 1							    1 3							    1 2							    1 2 3
2 3 4							    2 4							    1 1							    3 3 3
														            2 1							    0 4 3

Matriks akhir                       Matriks akhir                   Matriks akhir                   Matriks akhir
hasil transformasi :		        hasil transformasi :		    hasil transformasi :            hasil refleksi :
4 1							        3 1							    2 1 1						    3 2 1			
3 1							        4 2							    1 1 2						    3 3 3
2 1								    Teka-teki terlalu sulit!	    Teka-teki terlalu sulit!        3 4 0
Teka-teki terlalu sulit!                                                                            Teka-teki       
                                                                                                    berhasil dipecahkan
*/

// Janji
/*
    Saya Mia Karisma Haq Asisten Pemrograman 13 dengan penuh kesadaran dan tanggung jawab untuk keberkahanNya membuat pembahasan soal TP1 dalam mata kuliah Algoritma dan Pemrograman 2 seperti yang telah dispesifikasikan. Aamiin
*/  

// Kode Program
// Deklarasi Library
#include <stdio.h>

/* Deklarasi Prosedur Fungsi yang digunakan */
// Fungsi untuk menghitung jumlah total baris dan kolom terakhir pada matriks
int sum(int n, int m, int matriks[n][m])
{
    int total = 0; // Inisialisasi nilai total, variabel ini digunakan untuk menampung total penjumlahan kolom dan baris terakhir pada matriks
    /* Perulangan untuk menghitung jumlah total baris dan kolom terakhir pada matriks */
    for (int i = 0; i < n; i++) // Perulangan dilakukan sebanyak n baris matriks
    {
        for (int j = 0; j < m; j++) // Perulangan dilakukan sebanyak m kolom matriks
        {
            if (j == m - 1) total += matriks[i][j]; // Jika indeks kolom saat ini merupakan kolom terakhir maka jumlahkan nilai elemen matriks saat ini
            
            if (i == n -1) total += matriks[i][j]; // Jika indeks baris saat ini merupakan baris terakhir maka jumlahkan nilai elemen matriks saat ini
        }
    }

    return total; // Menyatakan keluaran dari fungsi sum() adalah nilai total
}

// Fungsi untuk menandai arah rotasi
int arah_rotasi(int jumlah) { 
	if(jumlah%2 == 0) //Jika hasil penjumlahan bernilai genap maka lakukan rotasi ke kanan
    { 
		jumlah = 1; //Set 1 untuk rotasi ke kanan
	}
	else //Jika hasil penjumlahan bernilai ganjil maka lakukan rotasi ke kiri
    { 
		jumlah = 2; //Set 1 untuk rotasi ke kiri
	}
	
	return jumlah; //Menyatakan hasil keluaran dari fungsi arah_rotasi() adalah nilai jumlah
}

// Prosedur untuk menampilkan hasil refleksi
void refleksi(int n, int m, int arr[n][m])
{
    // Menampilkan matriks hasil refleksi
    printf("\nMatriks akhir hasil refleksi :\n");
    for (int i = 0; i < n; i++) // Perulangan sebanyak n baris matriks
    {
        for (int j = m-1; j >= 0; j--) // Perulangan sebanyak m kolom matriks
        {
            printf("%d", arr[i][j]); // Menampilkan elemen pada setiap matriks

            if (j != 0) printf(" "); // Menampilkan spasi antar elemen
        }
        printf("\n"); // Menampilkan baris baru
    }
    printf("Teka-teki berhasil dipecahkan!\n"); // Pesan konfirmasi bahwa hasil akhir dari matriks adalah refleksi
}

// Prosedur untuk menampilkan hasil transpose
void transpose(int n, int m, int arr[n][m])
{
    // Menampilkan matriks hasil refleksi
    printf("\nMatriks akhir hasil transpose :\n");
    for (int i = 0; i < m; i++) // Perulangan sebanyak m baris matriks
    {
        for (int j = 0; j < n; j++) // Perulangan sebanyak n kolom matriks
        {
            printf("%d", arr[j][i]); // Menampilkan elemen pada setiap matriks

            if (j != n - 1) printf(" "); // Menampilkan spasi antar elemen
        }
        printf("\n"); // Menampilkan baris baru
    }
    printf("Teka-teki terlalu sulit!\n"); // Pesan konfirmasi bahwa hasil akhir dari matriks adalah transpose
}

// Prosedur untuk rotasi 
void rotasi(int n, int m, int matriks[n][m])
{
    int compare = 0; // Inisialisasi nilai compare, variabel ini digunakan untuk menampung jumlah elemen yang sama pada dua matriks

    if (sum(n, m, matriks) % 2 == 0) // Jika hasil penjumlahan bernilai genap
    {
        int matriks_rotasi[n][m]; // Deklarasi matriks hasil rotasi dengan baris sebanyak baris dan kolom sebanyak kolom
		
        // Perulangan untuk rotasi matriks
		for(int i = 0; i < n; i++) // Perulangan sebanyak n baris matriks
        { 
			for(int j = 0; j < m; j++) // Perulangan sebanyak m kolom matriks
            { 
				if((sum(n, m, matriks) % 4) == 2) // Jika jumlah putaran sebanyak 2 kali ke kanan/kiri
                { 
					/* Maka indeks baris matriks_rotasi diisi nilai baris matriks awal dikurangi i tambah 1 
                    dan indeks kolom matriks_rotasi diisi nilai kolom matriks awal dikurangi j tambah 1 */
					matriks_rotasi[i][j] = matriks[n-(i+1)][m-(j+1)];
				}
				else if((sum(n, m, matriks) % 4) == 0) // Jika jumlah putaran sebanyak 4 kali ke kanan/kiri
                { 
					/* Maka setiap elemen matriks rotasi diisi elemen matriks awal */
					matriks_rotasi[i][j] = matriks[i][j];
				}

                // Membandingkan jumlah elemen yang sama pada matriks hasil rotasi dengan matriks awal
                if (matriks_rotasi[i][j] == matriks[i][j]) compare++;
			}
		}

        if (n * m == compare) refleksi(n, m, matriks_rotasi); // Jika kedua matriks sama maka lakukan refleksi
        else transpose(n, m, matriks_rotasi); // Jika berbeda maka lakukan transpose
    }
    else //Jika jumlah putaran ganjil
    {
		int matriks_rotasi[m][n]; // Deklarasi matriks hasil rotasi dengan baris sebanyak kolom dan kolom sebanyak baris

		//Perulangan untuk rotasi matriks
		for(int i = 0; i < m; i++) { // Perulangan sebanyak m baris matriks
			for(int j = 0; j < n; j++) { // Perulangan sebanyak n kolom matriks
				if(((sum(n, m, matriks) % 4) + arah_rotasi(sum(n, m, matriks)) == 2) || ((sum(n, m, matriks) % 4) + arah_rotasi(sum(n, m, matriks)) == 5)) // Jika jumlah rotasi sebanyak 1 kali ke arah kanan atau 3 kali ke arah kiri
                { 
					/* Maka indeks baris matriks_rotasi diisi nilai baris matriks awal dikurangi j tambah 1 dan kolom matriks_rotasi diisi i */
					matriks_rotasi[i][j] = matriks[n-(j+1)][i];
				}
				else // Jika jumlah rotasi sebanyak 1 kali ke arah kiri atau 3 kali ke arah kanan
                {
					/* Maka indeks baris matriks_rotasi diisi j dan kolom matriks_rotasi diisi nilai kolom matriks awal dikurangi i tambah 1 */
					matriks_rotasi[i][j] = matriks[j][m-(i+1)];
				}

                // Membandingkan jumlah elemen yang sama pada matriks hasil rotasi dengan matriks awal
                if (matriks_rotasi[i][j] == matriks[i][j]) compare++;
			}
		}
        
        if (n * m == compare) refleksi(m, n, matriks_rotasi); // Jika kedua matriks sama maka lakukan refleksi
        else transpose(m, n, matriks_rotasi); // Jika berbeda maka lakukan transpose
	}

}

// Program Utama
int main()
{
    int n, m; // Deklarasi variabel untuk baris dan kolom matriks

    scanf("%d%d", &n, &m); // Meminta masukan dari user untuk ukuran matriks
    int matriks[n][m]; // Deklarasi matriks sebanyak n baris dan m kolom

    /* Perulangan untuk mengisi elemen matriks */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
    }

    /* Menampilkan matriks awal */
    printf("Matriks awal :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", matriks[i][j]);

            if (j != m - 1) printf(" ");
        }
        printf("\n");
    }
    
    /* Memanggil prosedur rotasi untuk melakukan rotasi terhadap matriks */
    rotasi(n, m, matriks);

    return 0; // Menyatakan keluaran dari fungsi main() adalah true
}