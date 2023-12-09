#include <stdio.h>
/*
//struktur
void iniprosedur(int n)
{
    if (n == 0)
    {                                   //base condition
        printf("base. n = %d\n", n);
        return;
    }
    else
    {
        printf("%d\n", n);
        iniprosedur(n-1);               //rekursif
    }
}

int main()
{
    iniprosedur(3);                     //awal pemanggilan prosedur
    return 0;
}
*/
/*
//ex 1
void alfabet(int i)
{
    printf("%c", i);
    if (i < 'z')
    {
        alfabet(i+1);
    } 
}

int main()
{
    alfabet('a');
    return 0;
}
*/
/*
//ex 2 (while loop)
int fact(int n)
{
    int res =1;
    while(n != 0)
    {
        res = res * n;
        n--;
    }
    return res;
}

int main()
{
    printf("%d\n", fact(5));
    return 0;
}
*/
/*
//ex 2 (rekursif)
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact (n -1);
    }
}
int main()
{
    printf("%d\n", fact(5));
    return 0;
}
*/

//latihan (soal 1)
void alfabet(int i)
{
    printf("%c", i);
    if (i > 'a')
    {
        alfabet(i-1);
    } 
}

int main()
{
    alfabet('z');
    return 0;
}


//soal 2
