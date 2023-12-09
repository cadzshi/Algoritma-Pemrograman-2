#include <stdio.h>
#include <time.h>
/*
//matriks tipe bentukan titik
typedef struct
{
    int x, y;
} titik;

int main()
{
    titik matrix[4][4];
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("masukkan koordinat x:\n");
            scanf("%d", &matrix[i][j].x);
            printf("masukkan koordinat y:\n");
            scanf("%d", &matrix[i][j].y);
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("koordinat x: %d\n", &matrix[i][j].x);
            printf("koordinat y: %d\n", &matrix[i][j].y);
        }
    }
    return 0;
}
*/
/*
//simulasi rgb pada piksel
typedef struct
{
    int red, green, blue;
} piksel;

int main()
{
    int b, k;

    printf("masukkan banyak baris\n");
    scanf("%d", &b);
    printf("masukkan banyak kolom\n");
    scanf("%d", &k);

    piksel arr[b][k];

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < k; j++)
        {
            arr[b][k].red = 255;
            arr[b][k].green = 255;
            arr[b][k].blue = 255;
        }
        
    }
    arr[0][1].red = 0;
    arr[0][1].green = 255;
    arr[0][1].blue = 0;

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if ((arr[b][k].red == 255) && (arr[b][k].green == 255) && (arr[b][k].blue == 255))
            {
                printf("putih");
            }
            else if ((arr[b][k].red == 0) && (arr[b][k].green == 255) && (arr[b][k].blue == 0))
            {
                printf("hijau");
            }
        }
        printf("\n");
    }
    
    return 0;
}
*/
/*
//matriks untuk game tic tac toe
int main()
{
    //membersihkan layar 
    system("cls");
    int papan[3][3];
    //angka 1 untuk pemain pertama berupa huruf O
    //angka 2 untuk pemain kedau berupa huruf X
    int i, j, k;

    //inisialisasi papan diisi 0 semua
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            papan[i][j] = 0;
        }
    }
    //awalnya pemain diset -1 sebagai penanda permainan belum dimulai
    int pemain = -1;
    //x dan y juga diset  -1 sebagai penanda permainan belum dimulai
    int x = -1, y = -1;
    for (i = 0; i < 9; i++)
    {
        //mengisi papan jika ada masukan dari pemain
        if ((x != -1) && (y != -1))
        {
            papan[x][y] = pemain;
        }
    }
    //menggambar papan 
    printf("Kondisi papan:\n");
    printf("-------------\n");
    for (j = 0; j < 3; j++)
    {
        printf("| ");
        for (k = 0; k < 3; k++)
        {
            if (papan[k][j] == 0)
            {
                //jika papan kosong
                printf("  | ");
            }
            else if (papan[k][j] == 1)
            {
                //jika papan diisi oleh pemain pertama
                printf("O | ");
            }
            else if (papan[k][j] == 2)
            {
                //jika papan diisi pemain kedua
                printf("X  | ");
            }
        }
        printf("\n-------------\n");
    }
    printf("\n");

    //pergantian pemain yang akan mengisi papan
    if(pemain == 1)
    {
        pemain = 2;
    }
    else
    {
        pemain = 1;
    }
    //meminta masukan pemain
    printf("Masukkan X, Y (Pemain %d) : ", pemain);
    scanf("%d %d", &x, &y);
    //membersihkan layar 
    system("cls");
    return 0;
}
*/

//animasi sederhana walking b
//this is the procedure for making delay
void wait(float x)
{
    time_t start; //start time
    time_t current; //currrent time
    time(&start); //making start time
    do
        time(&current); //making the current time
        //doing checking while the different time under x and
        //meet the ending if the different time is x
    while (difftime(current, start) < x);
}
int main()
{
    //make the matrix
    char arr[6][6];

    //making variables
    //i and j as the counters
    //x and y as the coordinates in the matrix 
    //jalan as making variable, whether the direction up or down
    int i, j, x = -1, y = -1, jalan = 1;

    //inisialize the matrix
    //filled with -
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            arr[i][j] = '-';
        }
        
    }
    //loopin' 4ever
    while (1)
    {
        //clear the screen
        system("cls");

        //setting back the cell which is filled with B before
        if ((x >= 0) && (x < 6))
        {
            arr[x][y] = '-';
        }
        //the drawing constraints for the coordinate
        if ((x == 6) && (y == 6))
        {
            //bottom border as the mark of going up
            jalan = -1;
            x = x - 1;
            y = y -1; 
        }
        else if ((x == -1) && (y == -1))
        {
            //upper border as the mark of going up
            jalan = 1;
            x = x + 1;
            y = y + 1; 
        }
        else if (jalan == 1)
        {
            //if the direction is still going down 
            x = x + 1;
            y = y + 1;
        }
        else
        {
            //if the direction is still going up
            x = x - 1;
            y = y - 1;
        }
        //fill the cell with B
        if ((x >= 0) && (x < 6))
        {
            arr[x][y] = 'B';
        }
        
        //draw to the screen
        for (i = 0; i < 6; i++)
        {
            for ( j = 0; j < 6; j++)
            {
                if (arr[i][j] == '-')
                {
                    printf("   ");
                }
                else
                {
                    printf(" %c ", arr[i][j]);
                }
            }
            printf("\n");
        }
        //the delay procedur for 1 second
        wait(1);
    }
    
    return 0;
}