#include<stdio.h>
/*
//ex 1
int main()
{
    int matrix[4][5]; //deklarasi matriks sebanyak 4 baris 5 kata
    int i, j;         //deklarasi vriabel untuk iterasi 
    int bantu = 11;   //deklarasu variabel bantu untuk mengis matrik

    for (i = 0; i < 4; i++)         //perulangan sebanyak baris
    {                                
        for (j = 0; j < 5; j++)     //perulangan sebanyak kolom 
        {
            matrix[i][j] = bantu++; //mengisi nilai pada matriks
        }
    }

    for (i = 0; i < 4; i++)         //perulangan sebanyak baris
    {
        for (j = 0; j < 5; j++)     //perulangan sebanyak kolom
        {
            //menampilkan ke isi matriks baris i kolom j ke layar
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/
/*
//ex 2
int main()
{
    int matrix[4][5]; //deklarasi matriks sebanyak 4 baris 5 kata
    int i, j;         //deklarasi vriabel untuk iterasi 
    int bantu = 11;   //deklarasu variabel bantu untuk mengis matrik

    for (i = 0; i < 4; i++)         //perulangan sebanyak baris
    {                                
        for (j = 0; j < 5; j++)     //perulangan sebanyak kolom 
        {
            matrix[i][j] = bantu++; //mengisi nilai pada matriks
        }
    }

    for (i = 0; i < 4; i++)         //perulangan sebanyak baris
    {
        for (j = 0; j < 5; j++)     //perulangan sebanyak kolom
        {
            //menampilkan ke isi matriks baris i kolom j ke layar
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    //menampilkan isi matrix tertentu
    int baris, kolom;

    printf("\n");
    printf("masukkan baris yang dicari: ");
    scanf("%d", &baris);

    printf("masukkan kolom yang dicari: ");
    scanf("%d", &kolom);

    printf("\n");
    printf("isi dari baris %d dan kolom %d adalah %d\n", baris, kolom, matrix[baris - 1][kolom - 1]);

    return 0;
}
*/

//soal